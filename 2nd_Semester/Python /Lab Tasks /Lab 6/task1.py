import json
from collections import Counter

# Exercise 1


def most_spoken_languages(filename):
    with open(filename, 'r') as file:
        data = json.load(file)

    languages = []
    for i in data:
        languages.extend(i["languages"])

    lang_count = Counter(languages)
    most_spoken = lang_count.most_common(10)

    return most_spoken


print(most_spoken_languages('countries_data.json'))
