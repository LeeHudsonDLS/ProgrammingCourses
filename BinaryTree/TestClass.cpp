class TestClass{
	int width,height;
	public:
		void set_values(int,int);
		int area(){return width*height;}
};

void TestClass::set_values(int x, int y){
	width = x;
	height = y;
}


