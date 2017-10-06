'''
    Complexity: O(n^2)
'''
def JobScheduler(job):
    job.sort(key=lambda x:x[2],reverse=True)
    n=len(job)
    slots=[False for i in range(n)]
    for i in range(n):
        '''picked one job now alloting slot'''
        for j in range(min(n,job[i][1]),0,-1):
            #if found free slot
            if(slots[j-1]==False):
                slots[j-1]=job[i]
                break
    return(slots)
    

def main():
    '''[job name,deadline,profit]'''
    job=[['a',5,200],['b',3,180],['c',3,190],['d',2,300],['e',4,120],['f',2,100]]
    slots=JobScheduler(job)
    profit,seq=0,[]
    for i in slots:
        if i:
            profit+=i[2]
            seq.append(i[0])
    print(*seq)
    print(profit)


if __name__=="__main__":
    main()

