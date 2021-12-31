def solution(x):
    # Your code here
    
    res = ""
    for c in x:
        if c<='z' and c>='a':
            res += 'z' - (c-'a')
        else:
            res += c
            
    return res


x = input()
print(solution(x))