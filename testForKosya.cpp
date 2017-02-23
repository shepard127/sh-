
const int SIZE = 20;
int arrayWithtTwo[SIZE];

int inputData(int* inputArray);
int calcData(int* resultInArr);
int printOutData(int* sumArray);

int main()
{
	int* p_array = malloc(SIZE * sizeof(int));
	
	printOutData(calcData(p_array));
	
}

int inputData(int* inputArray)
{
	printf("Заполните масссив цифрками");
	// ну мы его типа заполнили
	
	return inputArray; // вернули адрес на первый элемент массива
}

int calcData(int* resultInArr)
{
	// в эту функцию мы получили уже заполненный массивчик
	// мы тут типа выгребаем все двоички из массива и складываем их в другой массив arrayWithtTwo(он глобальный и его видим)
	
	return arrayWithtTwo;		// возвращаем указатель на первый элемент массива с двоичками
}

int printOutData(int *sumArray)
{
	int i = 0;
	while(i < SIZE)
	{
		printf("Сумма двоичек: %d", *(sumArray + i));
		i++;
	}	
	
}
