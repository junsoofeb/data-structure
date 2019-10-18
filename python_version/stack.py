class Stack(object):
    def __init__(self):
        self.items = []
        
    def isEmpty(self):
        return not bool(self.items)
        # self.items 리스트가 비어있다면 bool()이 false를 반환하니까 not으로 비어있을때 true 주도록 함
    
    def push(self, value):
        self.items.append(value)
        
    def pop(self):
        value = self.items.pop()
        if value is not None:
            return value
        else:
            print("Stack is empty!")
    
    def size(self):
        return len(self.items)
    
    def peek(self):
        if self.items:
            return self.items[-1]
        else:
            print("Stack is empty!")
            
    def __repr__(self):
        return repr(self.items)
    
stack = Stack()

empty_check = stack.isEmpty()
print(f"스택 비어있는가? >> {empty_check}")

for i in range(5):
    print(f"스택에 {i} push!")
    stack.push(i)

print("현재 스택 >>", stack)

for i in range(0, 5, 2):
    print(f"스택에서 {i} pop!")
    stack.pop()

print("현재 스택 >>", stack)
