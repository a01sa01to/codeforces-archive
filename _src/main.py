import os
import time
from datetime import datetime

import get
import fetch
from commit import commit


def main():
    lastSubId = get.last_submission_id()
    print("Last Submission ID:", lastSubId)

    submissions = fetch.submissions(lastSubId)

    print("Found {} submission(s)".format(len(submissions)))

    if len(submissions) == 0:
        print("No new submissions")
        return

    cnt = 1
    memo = {}
    time.sleep(2)
    for s in submissions:
        if s.contestId in memo:
            c = memo[s.contestId]
        elif s.contestId:
            c = fetch.contest(s.contestId).name
            memo[s.contestId] = c
        else:
            c = "Unknown Contest"
            memo[s.contestId] = c

        print(f"\r\033[1m ({cnt: 3}/{len(submissions): 3})\033[0m Submission #{s.id} ({c} {s.problem.index}, at {datetime.fromtimestamp(s.creationTimeSeconds)})", end="", flush=True)
        time.sleep(2)

        save_dir = os.path.join(os.path.dirname(__file__), "..", c)
        save_path = f"{save_dir}{os.sep}{s.problem.index}_{s.id}_{s.verdict}.{get.extension(s.programmingLanguage)}"

        os.makedirs(save_dir, exist_ok=True)
        with open(save_path, mode="w", encoding="UTF-8") as file:
            file.write("/*\n")
            file.write(f" * Author: a01sa01to\n")
            file.write(f" * Submission URL: {get.submission_url(s)}\n")
            file.write(f" * Submitted at: {datetime.fromtimestamp(s.creationTimeSeconds)}\n")
            file.write(f" * Problem URL: {get.problem_url(s)}\n")
            file.write(f" * Result: {s.verdict}\n")
            file.write(f" * Execution Time: {s.timeConsumedMillis} ms\n")
            file.write(" */\n\n")
            file.write(fetch.code(s))
        commit(s, save_path)
        cnt += 1

    print("All Done!")


if __name__ == "__main__":
    main()
