# include "hello-world.h"

int HelloWorldStep::execute(const int & tag, HelloWorldContext & ctxt) const {
	ctxt.out_tag.put(tag);
	ctxt.data.put(tag, tag);
	return CnC::CNC_Success;
}

int main(int argc, char* argv[]) {
	HelloWorldContext ctxt;
		
	//CnC::debug::trace_all( *this ); 
	//CnC::debug::collect_scheduler_statistics(*this);

	int n = 1;
	if (argc > 1) {
		n = atoi(argv[1]);
	} else {
		std::cout << "Using default value: " << n << std::endl;
	}
	
	for (int i=0; i<n; i++) {
		ctxt.in_tag.put(i);
	}
	
	ctxt.wait();
	
	CnC::item_collection<int, int>::const_iterator iter;
	std::cout << "Created items:" << std::endl;
    for (iter = ctxt.data.begin(); iter != ctxt.data.end(); iter++) {
        std::cout << iter->first << ": " << *iter->second << std::endl;
    }
}
