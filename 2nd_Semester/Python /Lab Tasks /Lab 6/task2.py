import json
from collections import Counter

# Exercise 2


def most_populated_countries(filename, n):

    with open(filename, 'r', encoding='utf-8') as file:
        countries_data = json.load(file)

    sorted_countries = sorted(countries_data, key=lambda x: x['population'], reverse=True)

    result = [
        {'country': country['name'], 'population': country['population']}
        for country in sorted_countries[:n]
    ]

    return result


print(most_populated_countries('countries_data.json', 10))
