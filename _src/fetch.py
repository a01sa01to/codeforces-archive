import requests
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait

import get
from datatypes import Submission, Contest


def code(s: Submission, driver: webdriver.Chrome) -> str:
    wait = WebDriverWait(driver, 10)
    url = get.submission_url(s)
    driver.get(url)
    driver.implicitly_wait(10)
    wait.until(EC.presence_of_element_located((By.ID, "program-source-text")))
    code = driver.find_element(By.ID, "program-source-text")
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
