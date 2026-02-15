target=real2frac
OBJS = main.o
$(target): $(OBJS)
	g++ $(DEBUG) -o $@ $^

debug: DEBUG=-g
debug: $(target)
%.o: %.cpp
	g++ $(DEBUG) -Wall -o $@ -c $^

clean:
	rm -f $(target) $(OBJS)

install: $(target)
	cp $^ $(HOME)/bin
