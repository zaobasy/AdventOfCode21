all:
	$(MAKE) -C ./lib
	$(MAKE) -C ./scripts

clean:
	$(MAKE) clean -C ./lib
	$(MAKE) clean -C ./scripts