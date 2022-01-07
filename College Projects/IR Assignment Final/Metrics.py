# -*- coding: utf-8 -*-
"""
Created on Fri Nov  8 21:29:22 2019

@author: USER
"""

import pickle
import random
import math

def jaccard(words1,words2):

    set1 = set()
    set2 = set()

    for item in words1:
        set1.add(item)

    for item in words2:
        set2.add(item)

    set_union = set1.union(set2)
    set_intersect = set1.intersection(set2)

    jacc = len(set_intersect)/len(set_union)

    return jacc

def cosine_sim(words1,words2):

    set1 = set();
    set2 = set();
    
    if(len(words1)==0 or len(words2)==0):
            return 0

    for item in words1:
        set1.add(item)

    for item in words2:
        set2.add(item)

    set_union = set1.union(set2)

    vector1 = {};
    vector2 = {};


    for item in set_union:
        vector1[item] = words1.count(item);
        vector2[item] = words2.count(item);


    temp1 = 0;

    for value in vector1.values():

        temp1 = temp1 + (value*value)

    temp1 = temp1**0.5

    for key in vector1:
        vector1[key] = vector1[key]/temp1;

    temp2 = 0;

    for value in vector2.values():

        temp2 = temp2 + (value*value)

    temp2 = temp2**0.5

    for key in vector2:
        vector2[key] = vector2[key]/temp2;

    sim = 0;

    for item in set_union:
        temp = vector1[item]*vector2[item]
        sim = sim+temp


    return sim

def test():
    nl=open(r"CleanDutch.txt","r",encoding='utf8')
    en=open(r"CleanEnglish.txt","r",encoding='utf8')
    
    nl=nl.readlines()
    en=en.readlines()
    
    nl1=[]
    for item in nl:
        nl1.append(item.strip())
    nl=nl1
    
    en1=[]
    for item in en:
        en1.append(item.strip())
    en=en1
    
    dict_nl=pickle.load(open(r"dict_nl.p","rb"))
    dict_en=pickle.load(open(r"dict_en.p","rb"))
    
    stats1={}
    stats3={}
    #For english to dutch
    
    for i in range(5000):
        a=random.randint(1,len(en))
        en_line=en[a]
        nl_line=nl[a]
        if(len(en_line)==0 or len(nl_line)==0):
            i-=1
            continue
        translated_nl=[]
        en_line=en_line.split()
        
        
        
        for item in en_line:
            word=dict_en[item]
            translated_nl.append(word)
        
        jac=jaccard(nl_line.split(),translated_nl)
        cos=cosine_sim(nl_line.split(),translated_nl)
        stats3[a]=cos
        stats1[a]=jac
    
    #For english to dutch
    
    stats2={}
    stats4={}
    
    for i in range(5000):
        a=random.randint(1,len(en))
        en_line=en[a]
        nl_line=nl[a]
        if(len(en_line)==0 or len(nl_line)==0):
            i-=1
            continue
        translated_en=[]
        nl_line=nl_line.split()
        
        for item in nl_line:
            try:
                word=dict_nl[item]
                translated_en.append(word)
                
            except KeyError:
                i-=1
                continue
        cos=cosine_sim(en_line.split(),translated_en)
        jac=jaccard(en_line.split(),translated_en)
        stats4[a]=cos
        stats2[a]=jac
    return (stats1,stats2,stats3,stats4)

    


        
p,q,r,s=test()
value=p.values()
sum=0
for item in  value:
    sum+=item
average1=sum/len(value)
print(average1)        

value=q.values()
sum=0
for item in  value:
    sum+=item
average2=sum/len(value)
print(average2)    

value=r.values()
sum=0
for item in  value:
    sum+=item
average3=sum/len(value)
print(average3)

value=s.values()
sum=0
for item in  value:
    sum+=item
average4=sum/len(value)
print(average4)    
    
    