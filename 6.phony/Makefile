SUBDIRS:= main test1 test2
.PHONY:subdirs $(SUBDIRS)
subdirs:$(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
clean:
	rm main/*.o test1/*.o test2/*.o
