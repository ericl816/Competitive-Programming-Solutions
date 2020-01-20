import requests
import os
import time

def extension(language):
    if language[0:2]=='PY': return '.py'
    elif language[0:4]=='JAVA': return '.java'
    elif language[0]=='C': return '.cpp'
    elif language[0:3]=='TUR': return '.t'
    elif language[0:3]=='RKT': return '.rkt'
    elif language[0:4]=='TEXT': return '.txt'
    elif language[0:4]=='PERL': return '.pl'
    elif language[0:2]=='BF': return '.bf'
    else:
        print("Language not found: ", language)
        return '.txt'

def toFileName(name):
        d = {'/':'-', '\\':'-', '*':'', '?':'', ':':'-', '<':' ', '>':' ', '"':"'", "|":'-'}
        for i in d:
                name=name.replace(i, d[i])
        return name

def saveProblem(group, name, language, text):
    f = open(group+"/"+toFileName(name)+extension(language), "w")
    f.write(text.encode('cp1252', errors='replace').decode('cp1252'))
    f.close()
header = {
    "Cookie":"__cfduid=d24085283f5042dbca39eb825bd6505bf1560397725; csrftoken=MBldH9WRLawANp3O8wo9MrFod9Gg12OUQ83Qri9JQQGPtwme19LXZmH2kBeOMd5z; _ga=GA1.2.2146370845.1560397726; sessionid=zn62d66eo8p95d903suo0fdpag4mpjwp; _gid=GA1.2.660928067.1577586666; _gat=1" #whatever your Cookie header is
    }

def getSubmission(submissionId):
        return requests.get("https://dmoj.ca/src/"+submissionId+"/raw", headers=header).text.replace('\r\n', '\r').replace('\r', '\n')

# returns whether submission a is better than submission b
def better(a, b):
    if not a["points"] == b["points"]:
        return a
    if a["points"] < b["points"]:
        return b
    if a["time"] < b["time"]:
        return a
    return b

username = "eric574" #whatever your username is
subs = requests.get("https://dmoj.ca/api/user/submissions/"+username).json() # a map from the submission id to the submission data
#remove submissions with compile errors or aborted submissions, because those can have null time, points, or memory
subs = {i:subs[i] for i in subs if subs[i]["status"] == "D"}

problems = requests.get("https://dmoj.ca/api/problem/list").json() # a map from problem name to the problem data

best = {} # a map from problem name to the submission id of the best submission
for i in subs:
    p = subs[i]["problem"]
    if (p not in best or p in best and better(subs[i], subs[best[p]])):
        best[p] = i

#set up folders for different categories/contests
groups = {problems[p]["group"] for p in best}
for name in groups:
    os.makedirs(name, exist_ok=True)
count = 0
for p in best:
    r = getSubmission(best[p]) # the code
    time.sleep(2) # 2 seconds per request
    saveProblem(problems[p]['group'], problems[p]['name'], subs[best[p]]['language'],r)
    count+=1
    if (count%10==0): print(count)

print("Done")