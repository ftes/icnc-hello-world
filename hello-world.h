# include <cnc/cnc.h>
# include <cnc/debug.h>

// graph (forward declaration)
struct HelloWorldContext;

// single step class, that takes input tag and produces output data
struct HelloWorldStep {
	int execute (const int & t, HelloWorldContext & c) const;
};

// describe the graph
struct HelloWorldContext : public CnC::context<HelloWorldContext> {
	CnC::step_collection<HelloWorldStep> step;
	CnC::tag_collection<int> in_tag;
	CnC::item_collection<int, int> data;
	
	HelloWorldContext () :
		CnC::context<HelloWorldContext>(),
		step(*this, "step"),
		in_tag(*this, "in tags"),
		data(*this, "data") {
			in_tag.prescribes(step, *this);
			step.produces(data);
	}
};

