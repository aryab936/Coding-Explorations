# -*- coding: utf-8 -*-
import collections
from copy import deepcopy
import pickle

# Removes all the below characters and puts ' ' in their place for easier splitting into words.
l=[",",".","!","\"","?",":",";",u"\u002F",u"\u0027","(",")","\\","'",'1','2','3','4','5','6','7','8','9','0',"-","_",u"\u201D",u"\u201C",u"\u2019",u"\u2018",u"\u0022",u"\u02BC",u"\u0149","\n"]

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

def cleanDutch(lines):
    finalDutch=[]
    for i in range(len(lines)):
        en=list(lines[i])
        string=""
        for item in en: 
            if item in l:
                string+=" " #append the special characters with " " (whitespace)
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

#calculating the first set of initial translation probablities
def initial_translation_probs(words_en,words_nl):
    return {english:{dutch:1/len(words_en)for dutch in words_nl}for english in words_en}

#calculate the eucledian distance
def euclidean_distance(vector1,vector2):
    sum=0
    vector1_keys=vector1.keys()
    
    for key in vector1_keys:
        for item in vector1[key]:
            sum+=(vector1[key][item]-vector2[key][item])**2
    return sum**0.5

#concludes the model when the dist reaches less than the threshold
def has_converged(prev,curr,threshold):
    dist=euclidean_distance(prev,curr)
    return dist<threshold

#performs one iteration of EM algorithm
def train_iteration(to_train,word_eng,word_dutch,total_s,prev_prob): 
    

	trans_prob = deepcopy(prev_prob)

	counts = {}
	for eng in word_eng:
		counts[eng] = {}
		for dut in word_dutch:
			counts[eng][dut] = 0

	totals = {};
	for dut in word_dutch:
		totals[dut] = 0

	for ele in to_train:
		es = ele['eng'].split()
		ds = ele['dut'].split()

		for e in es:

			total_s[e] = 0 # counts of the destination words weighted according to their translation probabilities

			for f in ds:
            
				total_s[e] += trans_prob[e][f];
        
		for e in es:
			for f in ds:

				counts[e][f] += (trans_prob[e][f]/total_s[e]);
				totals[f] += trans_prob[e][f]/total_s[e];


	for f in word_dutch:
		for e in word_eng:
			trans_prob[e][f] = counts[e][f]/totals[f];


	return trans_prob

#IBM model 1 with EM algorithm
def model1(threshold):
    corpusEn=readCorpus(r"CleanEnglish","english") 
    corpusNl=readCorpus(r"CleanDutch.txt","dutch") 
    
    
    to_train= [] 
    
    for i in range(len(corpusEn)): #english sentence to dutch sentence mapping
        temp = {}
        temp['eng'] = corpusEn[i]
        temp['dut'] = corpusNl[i]
        to_train.append(temp)
    
    wordsEn=list(extractWords(corpusEn))
    wordsNl= list(extractWords(corpusNl))

    
    total_s={en:0 for en in wordsEn}
    
    prevProbs=initial_translation_probs(wordsEn,wordsNl)
    converged=False
    
    iters=0
    
    while not converged: #iterating till the probablities converge
        curr_translation_probs=train_iteration(to_train,wordsEn,wordsNl,total_s,prevProbs)
        converged=has_converged(prevProbs,curr_translation_probs,threshold)
        prevProbs=curr_translation_probs
        iters+=1
    curr_translation_probs= collections.OrderedDict(curr_translation_probs)
    temp=[]
    for i in curr_translation_probs: #finding the value(dutch word) with max. probability
        list1 = max(curr_translation_probs[i], key=curr_translation_probs[i].get)
        temp.append(list1)

    res = {}
    for key in curr_translation_probs: # making ditionary with final english to dutch translation
        for value in temp:
            res[key]=value
            temp.remove(value)
            break  
        
    to_train=[]    #dutch sentence to english sentence mapping
    total_s={nl:0 for nl in wordsNl}
    
    prevProbs=initial_translation_probs(wordsNl,wordsEn)
    res1={}
    converged=False
    while not converged: #iterating till the probablities converge
        curr_translation_probs=train_iteration(to_train,wordsNl,wordsEn,total_s,prevProbs)
        converged=has_converged(prevProbs,curr_translation_probs,threshold)
        prevProbs=curr_translation_probs
        iters+=1
    curr_translation_probs= collections.OrderedDict(curr_translation_probs)
    temp=[]
    for i in curr_translation_probs: #finding the value(english word) with max. probability
        list1 = max(curr_translation_probs[i], key=curr_translation_probs[i].get)
        temp.append(list1)

    
    for key in curr_translation_probs: # making ditionary with final dutch to english translation
        for value in temp:
            res1[key]=value
            temp.remove(value)
            break    
    return (res,res1)

# Returns a dictionary of {'word':'line in which word appears'}
def find_common_lines():
    f=open(r"DistinctEnglish.txt","r",encoding='utf8')
    g=open(r"CleanDutch.txt","r",encoding='utf8')
    h=open(r"CleanEnglish.txt","r",encoding="utf8")
    i=open(r"DistinctDutch.txt","r",encoding="utf8")
    
    
    en_lines=h.readlines()
    nl_lines=g.readlines()
    
    dist_dutch=i.readlines()
    q=[]
    for item in dist_dutch:
        q+=[item.strip()]
    dist_dutch=q
    
    dist_english=f.readlines()
    q=[]
    for item in dist_english:
        q+=[item.strip()]
    dist_english=q
    
    dict_en={}
    
    for item in dist_english: #makes the dictionary with english word to sentences
        for i in range(len(en_lines)):
            if item in en_lines[i]:
                dict_en[item].append(i)
    
    dict_nl={}    
    
    for item in  dist_dutch: #makes the dictionary with english word to sentences
         dict_nl[item]=[]
         for i in range(len(nl_lines)):
             if item in nl_lines:
                 dict_nl[item].append(i)
   
    return (dict_en,dict_nl)

def model1_local(enLines,nlLines,threshold): #Documentation and comments same as model1
    to_train=[]
    for i in range(len(enLines)):
        temp = {}
        temp['eng'] = enLines[i]
        temp['dut'] = nlLines[i]
        to_train.append(temp)
    
    wordsEn={}
    for item in enLines:
        a=item.split()
        for word in a:
            wordsEn.add(word)
    
    wordsEn=list(wordsEn)
    
    wordsNl={}
    for item in nlLines:
        a=item.split()
        for word in a:
            wordsNl.add(word)
    wordsNl=list(wordsNl)
 
    total_s={en:0 for en in wordsEn}
    
    prevProbs=initial_translation_probs(wordsEn,wordsNl)
    converged=False
    
    iters=0
    
    while not converged:
        curr_translation_probs=train_iteration(to_train,wordsEn,wordsNl,total_s,prevProbs)
        converged=has_converged(prevProbs,curr_translation_probs,threshold)
        prevProbs=curr_translation_probs
        iters+=1
        
    curr_translation_probs= collections.OrderedDict(curr_translation_probs)
    temp=[]
    for i in curr_translation_probs:
        list1 = max(curr_translation_probs[i], key=curr_translation_probs[i].get)
        temp.append(list1)

    res = {}
    for key in curr_translation_probs:
        for value in temp:
            res[key]=value
            temp.remove(value)
            break    
    return res

def find_mappings():
    dict_en,dict_nl=find_common_lines() #finding the occurence lines for each distinct word using find_common_lines
    file_dutch=open(r"CleanDutch.txt","r",encoding='utf8')
    file_english=open(r"CleanEnglish.txt","r",encoding='utf8')
    
    en_lines=file_english.readlines()
    q=[]
    for item in en_lines:
        q+=[item.strip()]
    en_lines=q
    
    nl_lines=file_dutch.readlines()
    q=[]
    for item in nl_lines:
        q+=[item.strip()]
    nl_lines=q
    
    mappings_nl_to_en={} #final mappings of dutch to english
    mappings_en_to_nl={} #final mappings of english to dutch
    
    for item_nl in dict_nl:
        lines=dict_nl[item_nl]
        lines_dutch=[]
        lines_english=[]
        for i in lines:
            lines_dutch.append(nl_lines[i]) #making a list of the common  dutch lines
            lines_english.append(en_lines[i]) #making a list of the common  english lines
        to_iterate_nos_nl=[]
        
        for i in range(len(lines_dutch)):
            flag=0
            for j in range(i+1,len(lines_dutch)):
                wordsi=lines_dutch[i].split()
                wordsj=lines_dutch[j].split()
                seti=set()
                setj=set()
                for thing in wordsi:
                    seti.add(thing) #only adding the matching words
                for thing in  wordsj:
                    setj.add(thing)
                if len(seti.intersection(setj))==1:
                    to_iterate_nos_nl+=[i] #finally getting the two line numbers we need to iterate on  
                    to_iterate_nos_nl+=[j]
                    flag=1
                    break
            if flag==1:
                break
        to_iterate_english_lines=[]
        to_iterate_dutch_lines=[]
        for i in to_iterate_nos_nl:
            to_iterate_english_lines.append(lines_english[i]) #making a list of the relevant lines
            to_iterate_dutch_lines.append(lines_dutch[i])
        dictionary=model1_local(to_iterate_english_lines,to_iterate_dutch_lines,0.01) #performing model1 convergence over the common word
        mappings_nl_to_en[item_nl]=dictionary[item_nl]
    
    for item_en in dict_en: #similar to the previous loop except it maps dutch to english
        lines=dict_en[item_en]
        lines_dutch=[]
        lines_english=[]
        for i in lines:
            lines_dutch.append(nl_lines[i])
            lines_english.append(en_lines[i])
        to_iterate_nos_en=[]
        
        for i in range(len(lines_dutch)):
            flag=0
            for j in range(i+1,len(lines_dutch)):
                wordsi=lines_dutch[i].split()
                wordsj=lines_dutch[j].split()
                seti=set()
                setj=set()
                for thing in wordsi:
                    seti.add(thing)
                for thing in  wordsj:
                    setj.add(thing)
                if len(seti.intersection(setj))==1:
                    to_iterate_nos_nl+=[i]
                    to_iterate_nos_nl+=[j]
                    flag=1
                    break
            if flag==1:
                break
        to_iterate_english_lines=[]
        to_iterate_dutch_lines=[]
        for i in to_iterate_nos_en:
            to_iterate_english_lines.append(lines_english[i])
            to_iterate_dutch_lines.append(lines_dutch[i])
        dictionary=model1_local(to_iterate_english_lines,to_iterate_dutch_lines,0.01)
        mappings_en_to_nl[item_en]=dictionary[item_en]
    return (mappings_en_to_nl,mappings_nl_to_en)
        
        
def finalProject():
    mapping_per_model1=model1(0.005)
    mapping_per_model1_en=mapping_per_model1[0]
    mapping_per_model1_nl=mapping_per_model1[1]
    
    #mapping_per_innovated_model=findmappings()
    
    dict_nl=pickle.load(open(r"dict_nl.p","rb"))
    dict_en=pickle.load(open(r"dict_en.p","rb"))
    return (mapping_per_model1_en, mapping_per_model1_nl,dict_en,dict_nl)
    
def runDemoStuck():
    mappings=finalProject()
    mappings_per_model1_en=mappings[0]
    mappings_per_model1_nl=mappings[1]
    dict_en=mappings[2]
    dict_nl=mappings[3]

    choice='1'
    
    while (choice=='1'):
       finalMapping={}
       no=input("Which model do you want to use?")
       if(no=='1'):
           lang=input("Which language do you want to translate into?")
           if(lang=='en'):
               finalMapping=mappings_per_model1_en
           elif(lang=='nl'):
               finalMapping=mappings_per_model1_nl
       elif(no=='2'):
          lang=input("Which language do you want to translate into?")
          if(lang=='en'):
              finalMapping=dict_nl
          elif(lang=='nl'):
              finalMapping=dict_en
       query=input("Enter your sentence to translate.")
       query=query.strip()
       query=query.split()
       answer=""
       for item in query:
           answer+=finalMapping[item]
       print("Final translated sentence is:")
       print(answer)
       
       choice=input("Do you want to continue for another translation?")
       
def runDemoSmooth():
    dict_en=pickle.load(open(r"dict_en.p","rb"))
    dict_nl=pickle.load(open(r"dict_nl.p","rb"))
    
    choice='1'
    
    while (choice=='1'):
       finalMapping={}
       lang=input("Which language do you want to translate into?")
       if(lang=='en'):
           finalMapping=dict_nl
       elif(lang=='nl'):
           finalMapping=dict_en
       query=input("Enter your sentence to translate.")
       
       query=query.strip()
       query=query.split()
       answer=""
       for item in query:
           answer+=finalMapping[item]
       print("Final translated sentence is:")
       print(answer)
       
       choice=input("Do you want to continue for another translation?")
       
runDemoSmooth()
    
    
