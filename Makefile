all: 
	make -C code
	@mv code/game_of_life ./

clean:
	@make clean -C code

fclean:
	@make fclean -C code
	@rm -f game_of_life

re:			fclean	all

.PHONY:		all clean fclean re
