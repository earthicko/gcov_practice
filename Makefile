NAME			= app_abort_mission

FILENAME		= \
				abort_mission_treelike \
				abort_mission_non_treelike \
				test_driver \

SRCS			= $(addsuffix .c, $(FILENAME))
OBJS			= $(addsuffix .o, $(FILENAME))
GCOVS			= $(addsuffix .c.gcov, $(FILENAME))
GCDAS			= $(addsuffix .gcda, $(FILENAME))
GCNOS			= $(addsuffix .gcno, $(FILENAME))

CFLAGS			= -O0 -fprofile-arcs -ftest-coverage

MCDC_CHECKER_ID	= 2f83a89653e7

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

check_coverage:
	for c_filename in $(FILENAME) ; do \
		gcov -b $(NAME) --object-file $$c_filename ; \
	done

run_coverage: $(NAME)
	./$(NAME)
	make check_coverage

re:
	make fclean
	make $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	make clean
	$(RM) $(GCOVS) $(GCDAS) $(GCNOS)
	$(RM) $(NAME)

mcdc_check:
	for c_filename in $(SRCS) ; do \
		sudo docker run -it -v $(PWD):/code $(MCDC_CHECKER_ID) /code/$$c_filename ; \
	done

.PHONY: check_coverage run_coverage re clean fclean mcdc_check
