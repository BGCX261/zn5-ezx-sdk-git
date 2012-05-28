
LOG_FILE=build.log

all:
	@./buildall.sh 2>&1 | tee $(LOG_FILE)

libs:
	@./buildall.sh libs $(LIB) 2>&1 | tee $(LOG_FILE)

build:
	@./buildall.sh build 2>&1 | tee $(LOG_FILE)

show:
	@./buildall.sh show ${APP} 2>&1 | tee $(LOG_FILE)

apps:
	@./buildall.sh apps ${APP} 2>&1 | tee $(LOG_FILE)

daem:
	@./buildall.sh daem ${APP} 2>&1 | tee $(LOG_FILE)

game:
	@./buildall.sh game ${APP} 2>&1 | tee $(LOG_FILE)

opie:
	@./buildall.sh opie ${APP} 2>&1 | tee $(LOG_FILE)

emus:
	@./buildall.sh emus ${APP} 2>&1 | tee $(LOG_FILE)

sdls:
	@./buildall.sh sdls ${APP} 2>&1 | tee $(LOG_FILE)

test:
	@./buildall.sh test ${APP} 2>&1 | tee $(LOG_FILE)

cleanlog:
	@rm -f $(LOG_FILE)

