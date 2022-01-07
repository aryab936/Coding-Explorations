# -*- coding: utf-8 -*-
"""
Created on Fri Nov  8 19:51:53 2019

@author: USER
"""
# Module to perform cleaning and splitting the corpus into dictinct words

# Removes all the below characters and puts ' ' in their place for easier splitting into words.
l=[",",".","!","\"","?",":",";",u"\u002F",u"\u0027","(",")","\\","'",'1','2','3','4','5','6','7','8','9','0',"-","_",u"\u201D",u"\u201C",u"\u2019",u"\u2018",u"\u0022",u"\u02BC",u"\u0149",u"\u2013",u"\u005B",u"\u005D",u"\uFF0B",u"\u002B",u"\u002A"]

#cleans the given file for the items in 'l' for english corpus
def cleanEnglish(lines):
    finalEnglish=[]
    for i in range(len(lines)):
        en=list(lines[i])
        string=""
        for item in en: 
            if item in l:
                string+=" " #append the special characters with " " (whitespace)
            else:
                string+=item
        string=string.lower() #making the words lowercase
        finalEnglish+=[string]
    return finalEnglish

#cleans the given file for the items in 'l' for dutch corpus
def cleanDutch(lines):
    finalDutch=[]
    for i in range(len(lines)):
        en=list(lines[i])
        string=""
        for item in en: 
            if item in l:
                string+=" "  #append the special characters with " " (whitespace)
            else:
                string+=item
        finalDutch+=[string]
        string=string.lower() #making the words lowercase
    return finalDutch

#reads the corpus
def readCorpus(filename,string):
    with open(filename,"r",encoding="utf8") as f:
        corpus=f.readlines()
    if string=="english": 
        b= cleanEnglish(corpus)
        return b
    else:        
       b= cleanDutch(corpus)
       return b

# Takes the cleaned corpus and returns distinct words present in it.   
def extractWords(corpus):
    words= set()
    for sentence in corpus:
        temp = sentence.split()
        for word in temp:
            words.add(word)
    return words

#cleaning the corpus 
p=readCorpus(r"C:\Users\Saurabh\Downloads\Dutch_Updated.txt","dutch") #add address of initial english corpus
with open(r"CleanDutch.txt","w",encoding='utf8') as f:
    f.writelines(p)                              #cleaned english corpus with output as CleanEnglish.txt

p=readCorpus(r"C:\Users\Saurabh\Downloads\English_Updated.txt","english") #add address of initial english corpus
with open(r"CleanEnglish.txt","w",encoding='utf8') as f:
    f.writelines(p)                              #cleaned english corpus with output as CleanDutch.txt
    
#splitting into words
corpusEn=readCorpus(r"CleanEnglish.txt","english")
corpusNl=readCorpus(r"CleanDutch.txt","dutch")
wordsEn=list(extractWords(corpusEn)) #makes a list of all the distinct english words
wordsNl= list(extractWords(corpusNl)) #makes a list of all the distinct dutch words

with open(r"DistinctDutch.txt","w",encoding='utf8') as f:
    for item in wordsNl:
        f.write(item+"\n")
    
with open(r"DistinctEnglish.txt","w",encoding='utf8') as f:
    for item in wordsEn:
        f.write(item+"\n")
