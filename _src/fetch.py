import requests
from bs4 import BeautifulSoup

import get
from datatypes import Submission, Contest


def code(s: Submission) -> str:
    url = get.submission_url(s)
    res = requests.get(url).text
    soup = BeautifulSoup(res, "html.parser")
    code = soup.select_one("pre#program-source-text")
    if code is None:
        return "// Could not fetch submission.\n// Perhaps it is private or deleted."
    return code.text.replace("\r", "")


def submissions(lastSubId: int) -> list[Submission]:
    url = f"https://codeforces.com/api/user.status?handle=a01sa01to&from=1&lang=en"
    res = requests.get(url).json()
    if res["status"] != "OK":
        print("Error:", res["comment"])
        exit(1)
    subm = [Submission(**s) for s in res["result"]]
    subm = [s for s in subm if s.id > lastSubId]
    subm.reverse()
    return subm


def contest(contest_id: int) -> list[Contest]:
    url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&from=1&count=1&showUnofficial=false"
    res = requests.get(url).json()
    if res["status"] != "OK":
        print("Error:", res["comment"])
        exit(1)
    return Contest(**res["result"]["contest"])
