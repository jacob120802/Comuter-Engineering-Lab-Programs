#Hill Climb ALgorithm
def HillClimb(tempgraph,heuristic):
  Snode,Enode=input("Enter the starting and ending node : ").split(" ") #input  
  
  open=[(Snode,heuristic[Snode])]   #open list
  closed=[(Snode,heuristic[Snode])]   #closed list
  par={(Snode,heuristic[Snode]):None}   #parent list
  traversal=[]    #traversal list

  #while open is not empty run algorithm
  while len(open)>0:
    a=open.pop(0)   #choose next node
    open.clear()    #clear open list i.e. delete all previous nodes
    traversal.append(a)   #add a to traversal
    max_h=heuristic[a[0]] #we set max heuristic to heuristic of current node

    #find all child nodes
    temp=[(x,heuristic[x]) for x in tempgraph[a[0]] if (x,heuristic[x]) not in closed and heuristic[x]<max_h]   #[(B,8),(F,6)]
    #assign parent to child nodes
    for x in temp:
      par[x]=a
    
    #if temp generates no new child nodes and current node is not destination that means no solution => local minima
    if len(temp)==0 and a[0]!= Enode:
      print("No solution")
      break
    
    #if current node is destination node then solution is found
    if a[0] == Enode:
      break

    #open becomes list of new child nodes
    open=temp 
    open = sorted(open, key=lambda x: x[1]) #sort open
    #insert temp into closed list
    closed.extend(temp)

  #print traversal
  print("Traversal : ",traversal)
  current=(a[0],heuristic[a[0]])
  path=[(Snode)]
  while current!=(Snode,heuristic[Snode]):
    path.insert(1,current[0])
    current=par[current]
  
  print("Path : ", end="")
  for i in path:
    print(i,end="\n" if i[0]==Enode else "->")
  

#----------------------------------------Input and Function Call--------------------------------------------------------

# vertices=[x for x in input("Enter the vertices : ").split(" ")]     #input vertices
# heu=[int(x) for x in input("Enter the heuristic value for each vertex resp. : ").split(" ")]    #input corresponding heuristics 
# heuristics={}   #heuristic dictionary
# for i in range(len(vertices)):    #creating heuristic dictionary
#   heuristics[vertices[i]]=heu[i]

# edges=[x.split(",") for x in input("Enter the edges(a,b) : ").split(" ")]   #input edge

# graph={}  #graph dictionary
# for i in vertices:      #create vertex as keys and corresponding empty lists of adjacent vertices
#     graph[i]=[]
# for i in edges:     #for every edge append adjacent vertices
#   if(i[0] not in vertices or i[1] not in vertices):   #if edge has invalid vertex skip the edge
#     print("Invalid edge found")
#     continue
#   graph[i[0]].append(i[1])
#   graph[i[1]].append(i[0])

heuristics={'A': 10, 'B': 8, 'C': 5, 'D': 7, 'E': 3, 'F': 6, 'G': 5, 'H': 3, 'J':0, 'I':1}

graph={'A': ['B', 'F'], 'B': ['A','C','D'], 'D': ['C','B','E'], 'C': ['B','C','E'], 'F': ['A','G', 'H'], 'E': ['I', 'C','D','J'], 'H': ['F','I'], 
       'G': ['F','I'], 'J':['I','E'], 'I': ['G', 'H','J','E'], }

HillClimb(graph,heuristics)
