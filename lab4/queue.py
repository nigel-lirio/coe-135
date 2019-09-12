class Item:
    def __init__(self, x):
        self.data = x
        self.next = None
class LList:
    def __init__(self):
        self.start = None
    def ins(self, data):
        new_item = Item(data)
        if self.start is None:
            self.start = new_item
            return
        hold = self.start
        while hold.next is not None:
            hold = hold.next
        hold.next = new_item

    def pop(self):
        while self.start is not None:
            print(self.start.data)
            self.start = self.start.next
coolqueue = LList()
while(True):
    a = input("Enter int value (0 to exit):")
    if a == 0:
        break
    coolqueue.ins(a)
coolqueue.pop()