from typing import Generic, Optional


def ConvertVerdict(verdict: str) -> str:
    if verdict == "OK":
        return "AC"
    elif verdict == "WRONG_ANSWER":
        return "WA"
    elif verdict == "COMPILATION_ERROR":
        return "CE"
    elif verdict == "RUNTIME_ERROR":
        return "RE"
    elif verdict == "TIME_LIMIT_EXCEEDED":
        return "TLE"
    elif verdict == "MEMORY_LIMIT_EXCEEDED":
        return "MLE"
    elif verdict == "PRESENTATION_ERROR":
        return "PE"
    elif verdict == "IDLENESS_LIMIT_EXCEEDED":
        return "ILE"
    elif verdict == "SECURITY_VIOLATED":
        return "SV"
    elif verdict == "CRASHED":
        return "CR"
    elif verdict == "INPUT_PREPARATION_CRASHED":
        return "IPC"
    elif verdict == "CHALLENGED":
        return "CH"
    elif verdict == "SKIPPED":
        return "SK"
    elif verdict == "PARTIAL":
        return "PA"
    elif verdict == "TESTING":
        return "T"
    elif verdict == "REJECTED":
        return "RJ"
    elif verdict == "FAILED":
        return "F"
    else:
        return "Unknown"


def ignoreNone(kwargs, key):
    if key in kwargs:
        return kwargs[key]
    else:
        return None


class Contest:
    id: int
    name: str
    type: str
    phase: str
    frozen: bool
    durationSeconds: int
    startTimeSeconds: Optional[int]
    relativeTimeSeconds: Optional[int]
    preparedBy: Optional[str]
    websiteUrl: Optional[str]
    description: Optional[str]
    difficulty: Optional[int]
    kind: Optional[str]
    icpcRegion: Optional[str]
    country: Optional[str]
    city: Optional[str]
    season: Optional[str]

    def __init__(self, **kwargs):
        self.id = kwargs["id"]
        self.name = kwargs["name"]
        self.type = kwargs["type"]
        self.phase = kwargs["phase"]
        self.frozen = kwargs["frozen"]
        self.durationSeconds = kwargs["durationSeconds"]
        self.startTimeSeconds = ignoreNone(kwargs, "startTimeSeconds")
        self.relativeTimeSeconds = ignoreNone(kwargs, "relativeTimeSeconds")
        self.preparedBy = ignoreNone(kwargs, "preparedBy")
        self.websiteUrl = ignoreNone(kwargs, "websiteUrl")
        self.description = ignoreNone(kwargs, "description")
        self.difficulty = ignoreNone(kwargs, "difficulty")
        self.kind = ignoreNone(kwargs, "kind")
        self.icpcRegion = ignoreNone(kwargs, "icpcRegion")
        self.country = ignoreNone(kwargs, "country")
        self.city = ignoreNone(kwargs, "city")
        self.season = ignoreNone(kwargs, "season")


class Member:
    handle: str
    name: Optional[str]

    def __init__(self, **kwargs):
        self.handle = kwargs["handle"]
        self.name = ignoreNone(kwargs, "name")


class Problem:
    contestId: Optional[int]
    problemsetName: Optional[str]
    index: str
    name: str
    type: str
    points: Optional[float]
    rating: Optional[int]
    tags: list[str]

    def __init__(self, **kwargs):
        self.contestId = ignoreNone(kwargs, "contestId")
        self.problemsetName = ignoreNone(kwargs, "problemsetName")
        self.index = kwargs["index"]
        self.name = kwargs["name"]
        self.type = kwargs["type"]
        self.points = ignoreNone(kwargs, "points")
        self.rating = ignoreNone(kwargs, "rating")
        self.tags = kwargs["tags"]


class Party:
    contestId: Optional[int]
    members: list[Member]
    participantType: str
    teamId: Optional[int]
    teamName: Optional[str]
    ghost: bool
    room: Optional[int]
    startTimeSeconds: Optional[int]

    def __init__(self, **kwargs):
        self.contestId = ignoreNone(kwargs, "contestId")
        self.members = [Member(**member) for member in kwargs["members"]]
        self.participantType = kwargs["participantType"]
        self.teamId = ignoreNone(kwargs, "teamId")
        self.teamName = ignoreNone(kwargs, "teamName")
        self.ghost = kwargs["ghost"]
        self.room = ignoreNone(kwargs, "room")
        self.startTimeSeconds = ignoreNone(kwargs, "startTimeSeconds")


class Submission:
    id: int
    contestId: Optional[int]
    creationTimeSeconds: int
    relativeTimeSeconds: int
    problem: Problem
    author: Party
    programmingLanguage: str
    verdict: str
    testset: str
    passedTestCount: int
    timeConsumedMillis: int
    memoryConsumedBytes: int
    points: Optional[float]

    def __init__(self, **kwargs):
        self.id = kwargs["id"]
        self.contestId = ignoreNone(kwargs, "contestId")
        self.creationTimeSeconds = kwargs["creationTimeSeconds"]
        self.relativeTimeSeconds = kwargs["relativeTimeSeconds"]
        self.problem = Problem(**kwargs["problem"])
        self.author = Party(**kwargs["author"])
        self.programmingLanguage = kwargs["programmingLanguage"]
        self.verdict = ConvertVerdict(ignoreNone(kwargs, "verdict"))
        self.testset = kwargs["testset"]
        self.passedTestCount = kwargs["passedTestCount"]
        self.timeConsumedMillis = kwargs["timeConsumedMillis"]
        self.memoryConsumedBytes = kwargs["memoryConsumedBytes"]
        self.points = ignoreNone(kwargs, "points")
