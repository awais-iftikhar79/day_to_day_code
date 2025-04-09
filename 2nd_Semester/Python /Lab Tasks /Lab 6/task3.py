
import json
from collections import Counter

# Exercise 3


def load_stop_words(filename='stop_words.txt'):
    with open(filename, 'r', encoding='utf-8') as file:
        stop_words = set(file.read().split())
    return stop_words


def clean_text(text):
    text = text.lower()
    text = ''.join(char for char in text if char.isalpha() or char.isspace())
    return text


def remove_stop_words(text):
    stop_words = load_stop_words()
    words = text.split()
    cleaned_words = [word for word in words if word not in stop_words]
    return ' '.join(cleaned_words)


def get_word_sets(text):
    return set(text.split())


def check_text_similarity(file1_path, file2_path):
        with open(file1_path, 'r', encoding='utf-8') as file1:
            text1 = file1.read()

        with open(file2_path, 'r', encoding='utf-8') as file2:
            text2 = file2.read()
        text1 = clean_text(text1)
        text2 = clean_text(text2)

        text1 = remove_stop_words(text1)
        text2 = remove_stop_words(text2)

        set1 = get_word_sets(text1)
        set2 = get_word_sets(text2)

        intersection = len(set1.intersection(set2))
        union = len(set1.union(set2))

        similarity = intersection / union

        return {
            'similarity': round(similarity, 2),
            'intersection_words': list(set1.intersection(set2)),
            'unique_words_file1': list(set1 - set2),
            'unique_words_file2': list(set2 - set1)
        }


def main():
    file1 = 'michelle_obama_speech.txt'
    file2 = 'melina_trump_speech.txt'

    result = check_text_similarity(file1, file2)

    if isinstance(result, dict):
        print(f"\nSimilarity: {result['similarity'] * 100}%")
        print(f"\nCommon words: {len(result['intersection_words'])}")
        print(f"Unique words in file 1: {len(result['unique_words_file1'])}")
        print(f"Unique words in file 2: {len(result['unique_words_file2'])}")
    else:
        print(result)


if __name__ == "__main__":
    main()