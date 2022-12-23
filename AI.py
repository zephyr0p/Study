TTT

def ConstBoard(board):
    print("Current State Of Board : \n\n");
    for i in range (0,9):
        if((i>0) and (i%3)==0):
            print("\n");
        if(board[i]==0):
            print("- ",end=" ");
        if (board[i]==1):
            print("O ",end=" ");
        if(board[i]==-1):    
            print("X ",end=" ");
    print("\n\n");

def UserTurn(board):
    pos=input("Enter X's position from [1...9]: ");
    pos=int(pos);
    if(board[pos-1]!=0):
        print("Wrong Move!!!");
        exit(0) ;
    board[pos-1]=-1;

def minimax(board, player):
    x=analyzeboard(board);
    if(x!=0):
        return (x*player);
    pos=-1;
    value=-2;
    for i in range(0,9):
        if(board[i]==0):
            board[i]=player;
            score=-minimax(board,(player*-1));
            if(score>value):
                value=score;
                pos=i;
            board[i]=0;

    if(pos==-1):
        return 0;
    return value;

def CompTurn(board):
    pos=-1;
    value=-2;
    for i in range(0,9):
        if(board[i]==0):
            board[i]=1;
            score=-minimax(board, -1);
            board[i]=0;
            if(score>value):
                value=score;
                pos=i;
 
    board[pos]=1;

def analyzeboard(board):
    cb=[[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]];

    for i in range(0,8):
        if(board[cb[i][0]] != 0 and
           board[cb[i][0]] == board[cb[i][1]] and
           board[cb[i][0]] == board[cb[i][2]]):
            return board[cb[i][2]];
    return 0;

def main():
    board=[0,0,0,0,0,0,0,0,0];

    print("Computer : O Vs. You : X");
    player= input("Enter to play 1(st) or 2(nd) :");
    player = int(player);
    for i in range (0,9):
        if(analyzeboard(board)!=0):
            break;
        if((i+player)%2==0):
            CompTurn(board);
        else:
            ConstBoard(board);
            UserTurn(board);
       
    x=analyzeboard(board);
    if(x==0):
         ConstBoard(board);
         print("Draw!")
    if(x==-1):
         ConstBoard(board);
         print("X Wins! Y Loose !")
    if(x==1):
         ConstBoard(board);
         print("X Loose! O Wins !")

main()

----------------------------------------------------------------------------------------------------------

NQ_BT

N=int(input("Enter number of queens: "))
Board=[['_' for x in range(N)] for y in range(N)]
print(Board)

def printboard(Board):
    for i in Board:
        for j in i:
            print(j, end=" ")
        print('_')

def isSafe(Board, row, col):
    for i in range(col):
        if(Board[row][i]=='Q'):
            return False

    for i,j in zip(range(row,-1,-1), range(col,-1,-1)):
        if(Board[i][j]=='Q'):
            return False

    for i,j in zip(range(row,N,1), range(col,-1,-1)):
        if(Board[i][j]=='Q'):
            return False
    return True

def SolveQueen(Board, col):
    if(col>=N):
        return True
    for i in range(N):
        if(isSafe(Board,i,col)==True):
            Board[i][col]='Q'
            printboard(Board)
            print(' ')
            if(SolveQueen(Board, col+1)==True):
                return True
            Board[i][col]='_'
            print("\n...Backtracking Here...")
    return False

if SolveQueen(Board,0)==False:
    print("\nSolution does not exist")
else:
    print("\nThis is the final solution")
    printboard(Board)

----------------------------------------------------------------------------------------------------------

NQ_Hill

import random

N = int(input("Enter value of N in N-Queens Problem: "))

def checkPossibility(chessBoard, i, j):
    for row in range(len(chessBoard)):
        for element in range(len(chessBoard[row])):
            if chessBoard[row][element]=='Q':
                jDist = abs(j - element)
                iDist = abs(i - row)
                if i == row or j == element or jDist == iDist:
                    return False
    return True

def heuristicFunction(chessBoard, goal, i, j):
    count = 0
    for row in chessBoard:
        for element in row:
            if element == 'Q':
                count += 1
    if i != -1 and j != -1:
        count += 1
    return (goal-count)

chessBoard = [['_']*N for i in range(N)]

while heuristicFunction(chessBoard, N, -1, -1) != 0:
    chessBoard = [['_']*N for i in range(N)]
    for row in range (len(chessBoard)):
        dist = -1
        i = -1
        j = -1
        resultList = []
        for element in range(len(chessBoard[row])):
            if checkPossibility(chessBoard, row, element):
                hDist = heuristicFunction(chessBoard, N, row, element)
                if dist <= hDist:
                    dist = hDist
                    i = row
                    j = element
                    resultList.append([row, element])
        if len(resultList) > 0:
            idex, jdex = resultList[random.randint(0, len(resultList) - 1)]
            print("\ni index= ", idex, "\nj index= ", jdex)
            chessBoard[idex][jdex] = 'Q'
        for row1 in chessBoard:
            print("\t", row1)
        print("Heuristic value is: ", heuristicFunction(chessBoard, N, -1, -1))

print("Heuristic value is: ", heuristicFunction(chessBoard, N, -1, -1), "\n")
print("\nFollowing is the Global maxima soloution for", N, "Queen(s) problem with heuristic distance from the goal state: ", heuristicFunction(chessBoard, N, -1, -1), "\n\n")

for row in chessBoard:
    print("\t", row1)

print("\n")

----------------------------------------------------------------------------------------------------------

CB

import re
import long_responses as long
def message_probability(user_message, recognised_words, single_response=False, required_words=[]):
    message_certainty= 0
    has_required_words = True
    for word in user_message:
        if word in recognised_words:
            message_certainty+=1
    percentage =float(message_certainty)/float(len(recognised_words))
    for word in required_words:
        if word not in user_message:
            has_required_words = False
            break
    if has_required_words or single_response:
        return int(percentage*100)
    else:
            return 0
def check_all_messages(message):
    highest_prob_list = {}
    def response(bot_response, list_of_words,single_response= False, required_words=[]):
        nonlocal  highest_prob_list
        highest_prob_list[bot_response]=message_probability(message,list_of_words, single_response, required_words)
    response('Hello!',['hello','hi','sup','hey','heyo'],single_response=True)
    response('I am bot',['what\s','your','name'],required_words=['your','name'])
    response('I\'m doing fine, and you?',['how','are','you','doing'],required_words=['how'])
    response('Thank you!',['i','love','you','code','palace'],required_words=['code','palace'])
    response(long.R_EATING,['what','you','eat'],required_words=['you','eat'])
    best_match= max(highest_prob_list, key=highest_prob_list.get)

    return best_match

    print(highest_prob_list)
    return long.unknown() if highest_prob_list[best_match] < 1 else best_match
def get_response(user_input):
    split_message = re.split(r'\s+|[,;?!.-]\s*', user_input.lower())
    response = check_all_messages(split_message)
    return response
while True:
    print('Bot:'+ get_response(input('You: ')))

->long_responses-------------------------------------------------------

import random
R_EATING = "I don't like eating anything because I'm a bot obviously! "

def unknown():
    reponse= ['Could you please re-phrase that?',
              "...",
              "Sounds about right",
              "What does that mean?"][random.randrange(4)]
    return reponse
  
----------------------------------------------------------------------------------------------------------
  
G_Stack
  
  # -*- coding: utf-8 -*-
"""6_Goal_stack_planning.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1SUfjushzd3xzxAE2fed6e2oz3jmZeqx5
"""

#!/usr/bin/env python
# coding: utf-8

# In[1]:


import sys

#Some lists required for algorithm
start_state = [] #required for storing initial state
goal_state = []  #required for storing final state
current_state = [] #required for storing current ongoing state
planning_stack = [] #stack required in goal stack planning (only going to add sub goals)
actual_plan = []  #plan generated (output)

#actions and predicates
actions = ["stack", "unstack", "pickup", "putdown"]
predicates = ["on", "clear", "arm_empty", "holding", "on_table"]

#necessary functions required for algorithm

#Preconditions append functions:- 
def preconditions_stack(X, Y):
    planning_stack.append("holding "+str(X))
    planning_stack.append("clear "+str(Y))

def preconditions_unstack(X, Y):
    planning_stack.append("on "+str(X)+" "+str(Y))
    planning_stack.append("clear "+str(X))
    
def preconditions_pickup(X):
    planning_stack.append("arm_empty")
    planning_stack.append("on_table "+str(X))
    planning_stack.append("clear "+str(X))
    
    
def preconditions_putdown(X):
    planning_stack.append("holding "+str(X))

    
#Corresponding action required to satisfy the predicates    
def for_on(X, Y):
    planning_stack.append("stack "+str(X)+" "+str(Y))
    preconditions_stack(X, Y)
    
def for_ontable(X):
    planning_stack.append("putdown "+str(X))
    preconditions_putdown(X)
    
def for_clear(X):
    
    #Finding the block on which X is stacked
    check = "on "
    
    for predicate in current_state:
        if check in predicate:
            temp_list = predicate.split()
            
            if temp_list[2] == X:
                break
            
    Y = str(temp_list[1])
    
    #Appending Unstack operatrion
    planning_stack.append("unstack "+str(Y)+" "+str(X))
    preconditions_unstack(Y, X)
    
def for_holding(X):
    check = "on_table "+str(X)
    
    if check in current_state:
        planning_stack.append("pickup "+str(X))
        preconditions_pickup(X)
        
    else:
         #Finding the block on which X is stacked
        check = "on "
    
        for predicate in current_state:
            if check in predicate:
                temp_list = predicate.split()

                if temp_list[2] == X:
                    break

        Y = str(temp_list[1])

        #Appending Unstack operatrion
        planning_stack.append("unstack "+str(Y)+" "+str(X))
        preconditions_unstack(Y, X)
        
def for_armempty():
    print("\nArm empty predicate false\n")
    sys.exit()
    
    
    
#Effects of action
def effect_stack(X, Y):
    current_state.remove("holding "+str(X))
    current_state.remove("clear "+str(Y))
    
    current_state.append("on "+str(X)+" "+str(Y))
    current_state.append("clear "+str(X))
    current_state.append("arm_empty")
    
def effect_unstack(X, Y):
    current_state.remove("on "+str(X)+" "+str(Y))
    current_state.remove("clear "+str(X))
    current_state.remove("arm_empty")
    
    current_state.append("holding "+str(X))
    current_state.append("clear "+str(Y))
    
def effect_pickup(X):
    current_state.remove("arm_empty")
    current_state.remove("on_table "+str(X))
    current_state.remove("clear "+str(X))
    
    current_state.append("holding "+str(X))
    
def effect_putdown(X):
    current_state.remove("holding "+str(X))
    
    current_state.append("arm_empty")
    current_state.append("on_table "+str(X))
    current_state.append("clear "+str(X))
    





input_string = input("Enter start state:- ")
start_state = input_string.split("^")

input_string = input("Enter goal state:- ")
goal_state = input_string.split("^")

print("\nEntered Start State:- "+str(start_state))
print("\nEntered Goal State:- "+str(goal_state)+"\n")

current_state = start_state.copy()

for predicate in goal_state:
    planning_stack.append(predicate)
    
while len(planning_stack) > 0:
    print("Planning Stack:- "+str(planning_stack))
    print("Current State:- "+str(current_state)+"\n")
    
    top = planning_stack.pop()
    temp = top.split()
    
    if temp[0] in predicates: #if top of stack is predicate
        
        if top in current_state: #if predicate is true:
            continue #You have already poped it. 
            
        else: 
            #Already poped above
            
            #push corresponding action that will satisfy that predicate onto stack and push preconditions of that action
            if temp[0] == "on":
                for_on(temp[1], temp[2])
            elif temp[0] == "on_table":
                for_ontable(temp[1])
            elif temp[0] == "clear":
                for_clear(temp[1])
            elif temp[0] == "holding":
                for_holding(temp[1])
            elif temp[0] == "arm_empty":
                for_armempty()
                
    if temp[0] in actions: #if top of stack is action
        #Already poped above
        
        #perform the action i.e add and delete it's effects from current state
        if temp[0] == "stack":
            effect_stack(temp[1], temp[2])
        elif temp[0] == "unstack":
            effect_unstack(temp[1], temp[2])
        elif temp[0] == "pickup":
            effect_pickup(temp[1])
        elif temp[0] == "putdown":
            effect_putdown(temp[1])
        
        #add that action to the actual plan
        actual_plan.append(top)

print("Final Current State:- "+str(current_state))
        
print("\nPlan Generated:- \n")
for step in actual_plan:
    print(step)


# In[ ]:


#trial
#on B A^on_table A^clear B^arm_empty
#on A B^on_table B^clear A^arm_empty

#ques 1
#on B A^on_table A^on_table C^on_table D^clear B^clear C^clear D^arm_empty
#on C A^on B D^on_table A^on_table D^clear C^clear B^arm_empty


# In[ ]:
