#Creating your own thread
# from threading import *

# class nookmybus:
#     def buy(self):
#         print(current_thread().getName())
#         print("Confirming a seat")
#         print("Processing the payments")
#         print("Printing the tickets")
    
# obj= nookmybus()
# t1 = Thread(target=obj.buy)

# t2 = Thread(target=obj.buy)

# t3 = Thread(target=obj.buy)

# t1.start()
# t2.start()
# t3.start()

#thread communication
from threading import *
from time import *

class Producer:
    def __init__(self):
        self.products= []
        self.c =Condition()
    
    def produceList(self):
        self.c.acquire()

        for i in range(1,5):
            self.products.append("Products"+str(i))
            sleep(1)
            print("item added")
        self.c.notify()
        self.c.release()


class Consumer:
    def __init__(self,prod):
        self.prod=prod

    def consume(self):
        self.prod.c.acquire()
        self.prod.c.wait(timeout=0)
        self.prod.c.release()
        print("Order shipped",self.prod.products)

p = Producer()
c = Consumer(p)
t1 = Thread(target=p.produceList)
t2 = Thread(target=c.consume)
t1.start()
t2.start()