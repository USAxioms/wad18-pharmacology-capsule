CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2 -pedantic
LDFLAGS = -lm

OBJECTS = drug_properties_wad18.o drug_target_interactions_wad18.o adme_wad18.o pk_pd_modeling_wad18.o

all: test_pharmacology_wad18

test_pharmacology_wad18: $(OBJECTS) test_pharmacology_wad18.c
	$(CC) $(CFLAGS) -c test_pharmacology_wad18.c -o test_pharmacology_wad18.o
	$(CC) $(CFLAGS) -o test_pharmacology_wad18 $(OBJECTS) test_pharmacology_wad18.o $(LDFLAGS)

drug_properties_wad18.o: drug_properties_wad18.c drug_properties_wad18.h wad18_common.h
	$(CC) $(CFLAGS) -c drug_properties_wad18.c -o drug_properties_wad18.o

drug_target_interactions_wad18.o: drug_target_interactions_wad18.c drug_target_interactions_wad18.h wad18_common.h
	$(CC) $(CFLAGS) -c drug_target_interactions_wad18.c -o drug_target_interactions_wad18.o

adme_wad18.o: adme_wad18.c adme_wad18.h wad18_common.h
	$(CC) $(CFLAGS) -c adme_wad18.c -o adme_wad18.o

pk_pd_modeling_wad18.o: pk_pd_modeling_wad18.c pk_pd_modeling_wad18.h wad18_common.h
	$(CC) $(CFLAGS) -c pk_pd_modeling_wad18.c -o pk_pd_modeling_wad18.o

test: all
	./test_pharmacology_wad18

clean:
	rm -f *.o test_pharmacology_wad18

.PHONY: all test clean
