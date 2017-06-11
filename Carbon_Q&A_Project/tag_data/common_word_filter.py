#Purpose: common word filter; the output will be a .txt file with common words
# (user has control over cutoff); import total word frequency list take
# and make list of only words; filter out 'words' that are only nubmers;
# remove countries, continents, and states; after some cutoff, write out
# the file
#Joe Burg

##################################################################################

cutoff = input("How many words do you want to have in the filter? ")

all_words = []
with open('total_word_frequency.txt') as inputfile:
    for line in inputfile:
        all_words.append(line.strip().split())

countries = []
with open('countries.txt') as inputfile:
    for line in inputfile:
        countries.append(line.strip().lower())

continents = []
with open('continents.txt') as inputfile:
    for line in inputfile:
        continents.append(line.strip().split().lower())

states = []
with open('states.txt') as inputfile:
    for line in inputfile:
        states.append(line.strip().lower())


##################################################################################
#access the list of words only
most_common_words = []
for pair in all_words:
    most_common_words.append(pair[0])

#remove numbers, countries, continents, states
for word in most_common_words:
    if word[0] in '0123456789':
        for letter in word:
            if letter in '0123456789' and letter not in 'abcdefghijklmnopqrstuvwxyz':
                most_common_words.remove(word)

    elif word in countries:
        most_common_words.remove(word)

    elif word in continents:
        most_common_words.remove(word)

    elif word in states:
        most_common_words.remove(word)

#imploy cutoff
words_cutoff = most_common_words[:cutoff]

##################################################################################
dataFile = open('common_word_filter.txt', 'w')
for eachitem in words_cutoff:
    dataFile.write(" ".join(eachitem)+'\n')

dataFile.close()        