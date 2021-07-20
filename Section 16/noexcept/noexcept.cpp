void Foo()noexcept{
}
void Bar(){
}

int main(){
	void (*p)() ;
	p = Foo ;
	p() ;
}