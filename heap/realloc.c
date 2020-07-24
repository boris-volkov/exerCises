int main()
{
	char* ptr = (char*)malloc(16*sizeof(char));

	ptr = (char*)realloc(32*sizeof(char));

	free(ptr);

	return 0;

}
/*
 * realloc does not change the data in old block,
 * only expands an already allocated block.
 * if it cannot expand because of fragmentation, 
 * it will find a block that is large enough, 
 * and copy data from old block into new one.
 * it will also free the old block
