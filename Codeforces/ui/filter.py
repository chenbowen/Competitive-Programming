import csv
import functools

handle = "chenbowen"
myrating = 1600

allTags = ['', '2-sat', 'hashing', 'shortest paths', 'data structures', 'bitmasks', 'dsu', 'dfs and similar', 'brute force', 'binary search', 'greedy', 'divide and conquer', 'number theory', 'constructive algorithms', 'sortings', 'graph matchings', 'games', 'dp', 'meet-in-the-middle', 'graphs', 'string suffix structures', 'geometry', 'two pointers', 'probabilities', 'chinese remainder theorem', 'schedules', 'flows', 'fft', 'matrices', 'implementation', 'expression parsing', 'math', 'strings', 'ternary search', 'combinatorics', 'trees']
cntTags = [('schedules', 4), ('chinese remainder theorem', 5), ('2-sat', 7), ('fft', 7), ('meet-in-the-middle', 12), ('ternary search', 14), ('expression parsing', 16), ('graph matchings', 20), ('flows', 29), ('string suffix structures', 33), ('matrices', 43), ('games', 50), ('divide and conquer', 54), ('hashing', 59), ('shortest paths', 77), ('probabilities', 79), ('bitmasks', 89), ('dsu', 96), ('two pointers', 110), ('geometry', 132), ('strings', 146), ('trees', 150), ('number theory', 155), ('combinatorics', 157), ('', 171), ('graphs', 211), ('binary search', 248), ('sortings', 257), ('dfs and similar', 261), ('constructive algorithms', 294), ('data structures', 399), ('brute force', 420), ('greedy', 513), ('math', 531), ('dp', 590), ('implementation', 848)]

def getAllRawData():        #filter all submitted problem
    data = []
    with open("problems_full.csv", newline="") as pro_csv:
        allRaw = csv.DictReader(pro_csv)
        done = {}
        with open("user_activity.csv", newline="") as done_csv:
            doneRaw = csv.DictReader(done_csv)
            for row in doneRaw:
                if row["verdict"] == "OK":
                    done[row["contestID"]+row["problem_index"]] = 1
        for row in allRaw:
            if row["problemID"] in done:
                row["status"] = "Accepted"
            else:
                row["status"] = ""
            data.append(row)
    return data
def writeFile(data, filename):
    with open(filename, 'w') as csvfile:
        fieldnames = ['problemID', 'status', "problemRating" ,'tags']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for problem in data:
            # writer.writerow({'problemID': problem['problemID'], 'problemRating': problem['problemRating'], 'tags': problem['tags']})
            writer.writerow({'problemID': problem['problemID'], "status":problem["status"], 'problemRating': problem['problemRating']})

def outputAllPro(tag):
    raw = getAllRawData()
    data = []
    for row in raw:
        if tag in row["tags"]:
            data.append(row)
    data.sort(key=lambda x: int(x["problemRating"]))
    # writeFile(data, "problemset/all_"+tag+'.csv')      #目录必须存在
    outputHTML(data, "problemset/"+tag, tag, 0, 5001)

def outputProInRange(tag, x, y):
    raw = getAllRawData()
    data = []
    for row in raw:
        if tag in row["tags"] and x <= int(row["problemRating"]) < y:
            data.append(row)
    data.sort(key=lambda x: int(x["problemRating"]))
    # writeFile(data, "problemset/"+tag+str(x)+"-"+str(y)+'.csv')   #目录必须存在
    outputHTML(data, "problemset/"+tag+str(x)+"-"+str(y), tag, x, y)

def sortTags():
    raw = getAllRawData()
    cntTags = {}
    for row in raw:
        t = row["tags"][1:-1].split(", ")
        for tag in t:
            if tag in cntTags:
                cntTags[tag] += 1
            else:
                cntTags[tag] = 0
    data = []
    for tag in sorted(cntTags, key=lambda x:cntTags[x]):
        data.append((tag, cntTags[tag]))
    print(data)

def getProblemList(tag, rating):
    outputProInRange(tag, rating-100, rating)
    outputProInRange(tag, rating, rating+100)
    # outputAllPro(tag)

def outputHTML(data, filename,tag, l, r):
    html = open(filename+'.html', 'w')
    title = tag + "[" + str(l) + ", " + str(r) + ")"
    headerTemplate = """
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <style>
            body {
                background: url(../../img/stardust.png) no-repeat fixed;
                -webkit-background-size: 100% 100%;
                -moz-background-size: 100% 100%;
                -o-background-size: 100% 100%;
            }
            html, body, div, table, tr, td {
                padding: 0;
                margin: 0;
                border: none;
                font-size: 18px;
                text-align: center;
                font-family: "Source Code Pro", Microsoft Yahei, Arial, sans-serif;
            }

            table {
                padding:0;
                margin:0;
                width: 100%;
                border-spacing: 0;
                border-collapse: collapse;
                border-radius: 10px;
                background:white;
                opacity: 0.7;
            }

            .main_wrap {
                width: 700px;
                margin-left: auto;
                margin-right: auto;
            }

            a {
                text-decoration: none;
                color: black;
            }
            tr {
                height:40px;
                line-height:40px;
            }
            tr:hover {
                background-color: lightblue;
                color: white;
            }

            tr:hover a {
                color: white;
            }

            h1 {
                color:white;
                font-size: 22px;
            }
        </style>
        <title>""" + title + """
        </title>
    </head>
    <body>
        <div class="main_wrap">
            <h1>"""+ title +"""</h1>
            <table>
                <tbody>
                <thead>
                <tr>
                    <th>
                        <strong>ID</strong>
                    </th>
                    <th>
                        <strong>Status</strong>
                    </th>
                    <th>
                        <strong>Difficulty</strong>
                    </th>
                </tr>
                </thead>
    """
    html.write(headerTemplate)
    for problem in data:
        contestID = ""
        problem_index = ""
        if '0' <= problem["problemID"][-1] <= '9':
            problem_index = problem["problemID"][-2:]
            contestID = problem["problemID"][0:-2]
        else:
            problem_index = problem["problemID"][-1]
            contestID = problem["problemID"][0:-1]
        problemTemplate = '<tr><td><a href="http://codeforces.com/contest/'+contestID+\
        '/problem/'+problem_index+'">'+contestID+problem_index+'</a></td><td>'+\
        problem["status"]+'</td><td>'+problem["problemRating"]+'</td></tr>'
        html.write(problemTemplate)
    html.close()

workontopic = ["dp", "math", "greedy", "data structures"]
for tag in workontopic:
    getProblemList(tag, 1600)



