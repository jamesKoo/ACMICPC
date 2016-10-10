import re

def is_possible(eq):
    op_list = ['+', '-', '/', '*']
    op_cnt = 0
    for op in op_list:
        op_cnt += eq.count(op)
   
    num_cnt = len(re.findall('\d+', eq))
    
    if num_cnt - op_cnt is 1 :
        return True 
    else:
        return False
       
eq = input()
if is_possible(eq):
    try:
        eq = eq.replace('/', '//')
        print(int(eval(eq)))
    except:
        print('ROCK')
else:
    print('ROCK')
