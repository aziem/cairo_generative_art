.PHONY: clean

cairo_hello: cairo_hello.cpp
	g++ -lcairo $< -o $@

clean:
	$(RM) cairo_hello
