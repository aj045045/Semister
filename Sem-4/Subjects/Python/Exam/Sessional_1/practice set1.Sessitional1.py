# 1.	Write a Python program to sum all the items in a list
# hd=[12,11]
# s=0
# for i in hd:
#     s=s+i
# print(s)


# 2.	Write a Python program to get the largest number from a list
# hd=[12,11,89,76]
# i=hd[1]
# for j in hd:
#     if j > i:
#         i=j
       
        
# print(i,"Largest Number in LIST")
# 3.	Write a Python program to count the number of strings 
#       from a given list of 
#       strings. The string length is 2 or more 
#       and the first and last characters are the same.
# hd=["harsh","dedakiya","is","here","rrr"]
# for i in hd:
#     if len(i)>=2 and i[0]==i[-1]:
#         print(i,"String which is More than 2 letter and First Last is Same")
      
        
# 4.	Write a Python program to remove duplicates from a list. 
# rcc=["Amitabh","Bachan","Hiyaa","Hiyaa"]
# temp_rcc=[]
# for i in rcc:
#     if i not in temp_rcc:
#         temp_rcc.append(i) 
# rcc = temp_rcc
# print("Removed Duplicates" , rcc)


# 5.	Take two lists and returns True if they have at least one common member.
# l1=[6,"IsHarsh",7,"isViratKohli",8,"isJohnAbraham"]
# l2=[61,5,3,2,81]
# boolean=False
# for i in l1:
#     for j in l2:
#         if i == j:
#             boolean = True
# print (boolean,"-->is the Answer")


# 6.	Print a specified list after removing the 2th, 4th and 6th elements.
# hd=[10,20,30,40,50,60,70]# 0=10 1=20 2=30 3=40 4=40 5=60 6=70
# hd.remove(hd[1])
# hd.remove(hd[2])
# hd.remove(hd[3])
# print(hd)


# 7.	Find the average of 10 numbers using while loop
# m=0
# for i  in range(11):
#     m += i;
# avg=m/10
# print(avg,"is Average")


# 8.	Display the given integer in a reverse manner
# i=561
# rev_str = str(i)[::-1]
# rev_num = int(rev_str)
# print(rev_num,"--> Reversed Number")


# 9.	Find the sum of the digits of an integer using a while loop
# def sum_OF_digit(n):
#     sum=0
#     num_str = str(n)
#     i=0
#     while i < len(num_str):
#         digit = int(num_str[i])
#         sum += digit
#         i += 1
#     return sum
# print(sum_OF_digit(5564))


# 10.	Find the factorial of a number using recursion
# def fact(n): 
#     if n == 1:
#         return 1
#     else:
#         return n * fact(n-1)
# n=5
# print(fact(n))

# 17.	Remove duplicates from a list of lists.
# hd=[ [12,1] , [12,"fg"] , [12,1] , [2,11] , [12,1] ]
# g=[]
# for i in hd:
#     if i not in g:
#         g.append(i)
# print(g)


# 19.	Write a Python program to convert a list
# of multiple integers into a single integer.
# i=[1,2,3,4,5,6,7,8,8,9,9]
# jumangi=int(''.join(map(str,i)))
# print(jumangi)


# 22.	Check whether a string is palindrome or not
# string_baba = "NAMAN"
# string_dhongi_baba = "Trupal"
# tmp1=string_baba[::-1]
# tmp2=string_dhongi_baba[::-1]
# if tmp1 == string_baba:
#     print("palindrome",string_baba)
# if tmp2 != string_dhongi_baba:
#     print("Not Palindrome",string_dhongi_baba)


# 25.	Write a Python program to move all zero digits to
#       the end of a given list of numbers.
# num = [1,0,1,3,0,1]
# zero=num.count(0)
# for i in range(zero):
#     num.remove(0)
#     num.append(0)
# print(num)


# 31.	Create a multidimensional list (lists of lists) with random values
# import random
# rows =3 
# cols =3
# depth = 1
# avengers=[[random.random() for k in range(depth) for j in range(cols) ] for i in range(rows)]
# print (avengers)


# 32.	Check whether a given key already exists in a dictionary
# hf = {12:"ABC",13:"CVF","G":"F"}
# search_key = input("Enter a Key Search")
# print(search_key)
# if search_key in hf:
#     print("Yes it is in DICT")
# else:
#     print("Not in DICT")
# INCOMplete 32

# 35.	Sort a given dictionary by key
# hf = {12:"ABC",3:"CVF",90:"F"}
# d=hf[3]
# print(d)
# for i in hf:
#     if  hf[i] > d:
#         hf[i] = d
# print(hf)
# INCOMplete 35

# 37.	Combine two dictionary by adding values for common keys
# h1 = {1:11,3:31,9:66}
# h2 = {2:21,3:33,6:66}
# res={}
# for key in h1:
#     if key not in h2:
#         res[key]=h1[key]
        
# for key in h2:
#     if key not in h1:
#         res[key]=h2[key]
        
# for key in h1:
#     if key in h2:
#         res[key]=h1[key]+h2[key]
# print(res)


# 39.	Get the key, value and item in a dictionary(answer copied)
# my_dict = {"apple": 2, "banana": 3, "orange": 5}

# # Get the keys of the dictionary
# keys = my_dict.keys()

# # Get the values of the dictionary
# values = my_dict.values()

# # Get the items (key-value pairs) of the dictionary
# items = my_dict.items()

# # Print the keys, values, and items
# print("Keys:", keys)
# print("Values:", values)
# print("Items:", items)    


# 43.	Find the length of a dictionary of values
# my = {1: "apple", 3: "banana", 2: "orange"}

# for i  in my:
#     d=0
#     d=len(my[i])
#     print("Value Len is",d,"of",my[i])    

# 45.	Write a Python function 
# that accepts a string and counts the number of 
# upper and lower case letters
# Bheem = "Chutki is my Sister"
# u=0
# l=0
# for i in range(len(Bheem)):
#     if Bheem[i].isupper():
#         u += 1
#     if Bheem[i].islower():
#         l += 1
        
# print("Number of Lower is",l)        
# print("Number of Upper is",u)        


# 48.	Find if a given string starts with a given character using Lambda
# str1="harsh"
# str2="h"
# str3="a"
# st = lambda x: x.startswith(str2)
# result1 = st(str1)
# st = lambda x: x.startswith(str3)
# result2 = st(str1)
# print(result1)
# print(result2)


# 49.	Create Fibonacci series up to n using Lambda
# n = 10
# fib = lambda n: n if n <= 1 else fib(n-1) + fib(n-2)
# fib_series = [fib(i) for i in range(n)]
# print(fib_series)  

# 50.	Count the even and odd numbers in a given array of integers using Lambda
