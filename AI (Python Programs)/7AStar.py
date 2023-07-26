def ASTAR(root,destination,heuristic,graph) :
    open=[]
    close=[]
    test=[]
    #print(heuristic[0])
    list=[root,0,0,heuristic[root],0+heuristic[root]]
    open.append(list)
    test.append(root)   #test mei node
    while open:
        open.sort(key=lambda x: x[4])
        visited=open.pop(0)    #visited=['S',nil,0,7,7]
        close.append(visited)
        if (visited[0]==destination) :
            print("success")
            return close 
        else:
            children=graph[visited[0]] #children=[['A',1],['B',4]]
            for i in children : # i=['A',1]                 ,['B',4]
                if i[0] not in test : #i[0]='A'             ,'B'
                    list=[i[0],visited[0],i[1]+visited[2],heuristic[i[0]],i[1]+visited[2]+heuristic[i[0]]] #(a, s, )
                    open.append(list)
                    test.append(i[0])    
    print("No solution")

#solution=[['S', 0, 0, 7, 7], ['B', 'S', 4, 2, 6], ['A', 'S', 1, 6, 7], ['C', 'B', 6, 1, 7], ['D', 'A', 13, 0, 13]]
def path(solution,root):
    FinalPath=[]
    visited=solution[-1][0]         #CURRENT DESTINATION
    FinalPath.append(visited)
    visited=solution[-1][1] #'A     #PARENT
    while visited!=root:
        for i in solution:
            #Jab parent current banega tab hamme uska parent milega
            #i[0]=['S', 0, 0, 7, 7]
            #i=['S', 0, 0, 7, 7], ['B', 'S', 4, 2, 6], ['A', 'S', 1, 6, 7], ['C', 'B', 6, 1, 7], ['D', 'A', 13, 0, 13]
            if i[0]==visited:
                visited=i[0]       #PARENT=>CURRENT
                FinalPath.append(visited)
                visited=i[1]       #PARENT-=>CURRENT uska PARENT
                break
    FinalPath.append(root)
    FinalPath.reverse()
    return FinalPath
    
graph={
    'S':[['A',1],['B',4]],
    'A':[['D',12],['B',2],['C',5],['S',1]],
    'B':[['C',2],['A',2],['S',4]],
    'C':[['A',5],['D',3],['B',2]],
    'D':[['A',12],['C',3]]    
}

heuristic={
    'S':7,
    'A':6,
    'B':2,
    'C':1,
    'D':0
        }


root=input("enter the root: ")
destination=input("enter the destination: ")

solution=ASTAR(root,destination,heuristic,graph)
print(solution)

FinalPath=path(solution,root)
print(FinalPath)