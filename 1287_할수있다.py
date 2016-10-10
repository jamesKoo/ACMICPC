'''
1287 - 할 수 있다(https://www.acmicpc.net/problem/1287)

정의 : Big Integer, Postfix를 구현하여 사칙연산.
풀이 : Big Integer와 Postfix를 직접 구현하지 않고 파이썬 언어를 이용.
       - 파이썬에서는 기본적으로 Big Integer를 제공.
	   - Postfix구현 대신 eval()함수를 이용하여 문자열로 된 식을 계산.
'''

import re

def is_possible(eq):
    op_list = ['+', '-', '/', '*']
    op_cnt = 0
    for op in op_list:
        op_cnt += eq.count(op)
   
    num_cnt = len(re.findall('\d+', eq))
    
    if num_cnt - op_cnt is 1:
        return True 
    else:
        return False

# Input
eq = input()

# Calculate and Output
if is_possible(eq):
    try:
        eq = eq.replace('/', '//')
        print(int(eval(eq)))
    except:
        print('ROCK')
else:
    print('ROCK')
