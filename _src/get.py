import os
import json
import git

from datatypes import Submission


with open(os.path.join(os.path.dirname(__file__), "ext.json"), mode="r", encoding="UTF-8") as file:
    extensions = json.load(file)


def extension(lang: str) -> str:
    for v in extensions:
        if lang.startswith(v):
            return extensions[v]
    return "unknown"


def submission_url(s: Submission) -> str:
    return f"https://codeforces.com/contest/{s.contestId}/submission/{s.id}"


def problem_url(s: Submission) -> str:
    return f"https://codeforces.com/contest/{s.contestId}/problem/{s.problem.index}"


def last_submission_id() -> int:
    repo = git.Repo(".")
    if not repo.active_branch.is_valid():
        return 0

    for commit in repo.iter_commits():
        try:
            # Result ProbId (SubmissionID) at EpochSecond
            lastSubId = int(commit.message.split(" ")[-1].replace("(", "").replace(")", "")) + 1
            print("Found Last Submission Commit:", commit.message)
            return lastSubId
        except ValueError as err:
            print(f"ValueError ({err})", commit.message)
            continue
        except IndexError as err:
            print(f"IndexError ({err})", commit.message)
            continue
    return 0
