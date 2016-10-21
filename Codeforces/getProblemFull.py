import csv


dct = {}
ans = []
with open("problem_ratings.csv", newline="") as rat_csv:
    ratings = csv.DictReader(rat_csv)
    id = ""
    for problem in ratings:
        id = problem["contestID"] + problem["problemID"]
        dct[id] = {"problemRating":problem["problemRating"]}
        
    with open("problem_data.csv", newline="") as data_csv:
        data = csv.DictReader(data_csv)
        for problem in data:
            id = problem["contestID"] + problem["problemID"]
            if id in dct:
                dct[id]["tags"] = problem["tags"]
    for id in dct:
        ans.append((id, dct[id]["problemRating"] ,dct[id]["tags"]))


with open('problems_full.csv', 'w') as csvfile:
    fieldnames = ['problemID', "problemRating" ,'tags']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    for problem in ans:
        writer.writerow({'problemID': problem[0], 'problemRating': problem[1], 'tags': problem[2]})

