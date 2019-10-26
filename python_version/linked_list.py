class Node(object):
    def __init__(self, value = None, pointer = None):
        self.value = value
        self.pointer = pointer
        
    def getData(self):
        return self.value
    
    def getNext(self):
        return self.pointer
    
    def setData(self, newdata):
        self.value = newdata
        
    def setNext(self, newpointer):
        self.pointer = newpointer
        
LL = Node("a", Node("b", Node("c", Node("d"))))
print(LL.getData())
print(LL.getNext().getData())
print(LL.getNext().getNext().getData())
print(LL.getNext().getNext().getNext().getData())

'''
실행결과

a
b
c
d

'''