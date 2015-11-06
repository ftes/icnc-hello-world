# include "hello-world.h"

int HelloWorldStep::execute(const int & tag, HelloWorldContext & ctxt) const {
	ctxt.data.put(tag, tag*tag);
	return CnC::CNC_Success;
}

int main(int argc, char* argv[]) {
	HelloWorldContext ctxt;
		
	CnC::debug::trace_all(ctxt);
	CnC::debug::collect_scheduler_statistics(ctxt);

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
	
	std::cout << "Created items:" << std::endl;
	CnC::item_collection<int, int>::const_iterator iter;
    for (iter = ctxt.data.begin(); iter != ctxt.data.end(); iter++) {
        std::cout << iter->first << ": " << *iter->second << std::endl;
    }
}
