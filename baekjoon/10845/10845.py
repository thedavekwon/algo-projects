class queue:
    def __init__(self):
        self.length = 0
        self.q = []
    
    def push(self,x):
        self.q.append(x)
        self.length = self.length + 1

    def pop(self):
        if(self.length == 0):
            return -1
        else:
            tmp = self.q[0]
            self.q = self.q[1:]
            self.length = self.length - 1
            return tmp
    
    def size(self):
        return self.length
        
    def empty(self):
        if self.length == 0:
            return 1
        else:
            return 0
    
    def front(self):
        if(self.length == 0):
            return -1
        else:
            return self.q[0]
    
    def back(self):
        if(self.length == 0):
            return -1
        else:
            return self.q[-1]

q = queue()
tc = int(input())
while(tc):
    order = input().split()
    if(len(order)>1):
        if(order[0] == "push"):
            q.push(int(order[1]))
    else:
        if(order[0] == "pop"):
            print(q.pop())
        if(order[0] == "front"):
            print(q.front())
        if(order[0] == "back"):
            print(q.back())
        if(order[0] == "size"):
            print(q.size())
        if(order[0] == "empty"):
            print(q.empty())
    tc = tc - 1