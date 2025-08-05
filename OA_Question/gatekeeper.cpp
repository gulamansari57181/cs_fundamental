""" 
Phonepe OA : 

Question 1:

Gatekeeper [ {1,3} , {2,5} , {3 , 6} , {4 ,7} ]

Arrival [ 1 ,2 , 3 ,4]


Ans [1 , 2 ,  3 , 3] 


Brute  : O(n*m) two for loop

Optimize :  Line Sweep Algorithm


Step1 : prefix [ all value 0] , with size = max from (gatekeeper(maxvalue) , arriva(maxValue)l) +1 

	Optimixe size = arrival(maxValue) + 1 
			

Prefix = [0 0 0 0 0]

Step 2 : Execute all the query of gatekeeper in following way
Each query  GateKeeper array  a) pre[start] = pre[start] +1
                b ) prefix[end+1] = prefix[end+1] -1

Step 3 : Now compute prefixSum of prefix array

 prefixSum [ 0 , 1 ,2 , 3 , 3 , 2 , 1 , 0]


Step 4 :  Now for every arrival Time arrivals[i] = prefixSum[i] ;
"""