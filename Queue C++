class Queue
{
private:
	enum{
		ArrR_Size = 100,
		ArrL_Size = 5
		//Queue_Size = 500
	};
	int8_t head;
	int8_t tail;
	int8_t (*Data)[ArrL_Size];
public:
	Queue();
	~Queue();
	void QueuePush(int8_t* data);
	void QueuePop(int8_t* Rdata);
	int8_t* Get_Data();
	//int8_t QueueFront();
	//int8_t QueueBack();
	bool QueueEmpty();
};

Queue::Queue()
{
	head = 0;
	tail = 0;
	Data = new int8_t[ArrR_Size][ArrL_Size];
}

Queue::~Queue()
{
	delete[] Data;
}

void Queue::QueuePush(int8_t* data)
{
	int8_t tmp = 0;
	for(tmp = 0; tmp < ArrL_Size; tmp++)
		Data[tail][tmp] = data[tmp];
	tail = (tail + 1) % ArrR_Size;
}

void Queue::QueuePop(int8_t* Rdata)
{
	int8_t tmp = 0;
	for(tmp = 0; tmp < ArrL_Size; tmp++)
		Rdata[tmp] = Data[head][tmp];
	head = (head + 1) % ArrR_Size;
}

int8_t* Queue::Get_Data()
{
	return (int8_t*)Data;
}

bool Queue::QueueEmpty()
{
	return head == tail;
}
