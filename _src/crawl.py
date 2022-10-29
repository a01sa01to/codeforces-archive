import requests
import os
import time
import git
from datetime import datetime

from func import get_extension, get_submission_url, get_problem_url, fetch_submission, get_last_submission_id, commit
from datatypes import Submission, Contest


def fetch_submissions(lastSubId: int) -> list[Submission]:
    url = f"https://codeforces.com/api/user.status?handle=a01sa01to&from=1&lang=en"
    res = requests.get(url).json()
    if res["status"] != "OK":
        print("Error:", res["comment"])
        exit(1)
    subm = [Submission(**s) for s in res["result"]]
    subm = [s for s in subm if s.id > lastSubId]
    subm.reverse()
    return subm


def fetch_contest(contest_id: int) -> list[Contest]:
    url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&from=1&count=1&showUnofficial=false"
    res = requests.get(url).json()
    if res["status"] != "OK":
        print("Error:", res["comment"])
        exit(1)
    return Contest(**res["result"]["contest"])


def main():
    lastSubId = get_last_submission_id()
    print("Last Submission ID:", lastSubId)

    submissions = fetch_submissions(lastSubId)

    print("Found {} submission(s)".format(len(submissions)))

    if len(submissions) == 0:
        print("No new submissions")
        return

    cnt = 1
    memo = {}
    for s in submissions:
        time.sleep(2)
        if s.contestId in memo:
            c = memo[s.contestId]
        elif s.contestId:
            c = fetch_contest(s.contestId).name
            memo[s.contestId] = c
        else:
            c = "Unknown Contest"
            memo[s.contestId] = c

        print(f"\r\033[1m ({cnt: 3}/{len(submissions): 3})\033[0m Submission #{s.id} ({c} {s.problem.index}, at {datetime.fromtimestamp(s.creationTimeSeconds)})", end="", flush=True)

        save_dir = os.path.join(os.path.dirname(__file__), "..", c)
        save_path = f"{save_dir}{os.sep}{s.problem.index}_{s.id}_{s.verdict}.{get_extension(s.programmingLanguage)}"

        os.makedirs(save_dir, exist_ok=True)
        with open(save_path, mode="w", encoding="UTF-8") as file:
            file.write("/*\n")
            file.write(f" * Author: a01sa01to\n")
            file.write(f" * Submission URL: {get_submission_url(s)}\n")
            file.write(f" * Submitted at: {datetime.fromtimestamp(s.creationTimeSeconds)}\n")
            file.write(f" * Problem URL: {get_problem_url(s)}\n")
            file.write(f" * Result: {s.verdict}\n")
            file.write(f" * Execution Time: {s.timeConsumedMillis} ms\n")
            file.write(" */\n\n")
            file.write(fetch_submission(s))
        commit(s, save_path)
        cnt += 1

    print("All Done!")


if __name__ == "__main__":
    main()
