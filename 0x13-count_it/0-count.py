#!/usr/bin/python3
"""Count it problem
"""
import requests


def recurse(subreddit, word_list, hot_titles, after=""):
    """Recursive function that queries the Reddit API and
    prints a sorted count of given keywords
    Args:
        subreddit: string representing subreddit to search for
        word_list: collection of keywords to search in the
        subreddit
        hot_titles: dictionary of number of occurrences of elements
        in word_list that are found in the request
        after: pagination feature of the reddit api

    Return:
        hot_titles or None
    """
    url = "https://www.reddit.com/r/{}/hot.json?after={}".format(subreddit,
                                                                 after)
    res = requests.get(url,
                       headers={'User-agent': 'product'},
                       allow_redirects=False)

    if res.status_code != 200:
        return None
    if after is None:
        return hot_titles

    for i in res.json().get('data').get('children'):
        title_s = i.get('data').get('title').split()
        for word in set(word_list):
            if word.lower() in [x.lower() for x in title_s]:
                if hot_titles.get(word):
                    hot_titles[word] += 1
                else:
                    hot_titles[word] = 1

    after = res.json().get('data').get('after')
    recurse(subreddit, word_list, hot_titles, after)
    return hot_titles


def count_words(subreddit, word_list):
    """Calls recurse to get dictionary of ocurrences of word_list
    and prints that dictionary sorted by values in decreasing order

    Args:
        subreddit: string representing subreddit to search for
        word_list: collection of keywords to search in the
        subreddit
    Return:
        each keyword with its corresponding count in order
    """
    hot_titles = recurse(subreddit, word_list, {})
    if hot_titles:
        for k, v in sorted(hot_titles.items(), key=lambda val: val[1],
                           reverse=True):
            if v != 0:
                print('{}: {}'.format(k, v))
