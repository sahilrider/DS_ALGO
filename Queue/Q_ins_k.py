
queue = []
front = -1
rear = -1

def insert(value):
	global front
	global rear
	global queue
	if (front == -1):
		front = 0
	rear += 1
	queue.append(value)

def insertk(pos , val):
	global rear
	queue.append(0)
	for i in range(rear,pos,-1):
		queue[i+1] = queue[i]
	queue[pos-1] = val
	rear += 1

def display():
	if(rear == -1):
		print("EMPTY queue")
	else:
		for i in queue[front:rear]:
			print(i)

def main():
	
	for i in range(1,6):
		insert(i)
	display()
	insertk(3,10)
	display()
if __name__ == "__main__":
	main()