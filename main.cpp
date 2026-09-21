/*
 * ================================================================
 * Filename:    main.cpp
 * Description: ECE 412 Lab 2 -- driver. Exercises the ADT through
 *              the six numbered activities from the handout. This
 *              whole program must be valgrind-clean, and must NEVER
 *              touch db->anything -- if you cannot spell out the
 *              struct's fields, that is the ADT working correctly.
 * Created:     TODO
 * EID:         TODO
 * Email:       TODO
 * Author:      TODO
 * Provenance:  I certify that all code contained herein is mine
 *              alone except where otherwise noted.
 * ================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "db.h"
#include "mystr.h"

    /* ---- 1. Create + grow ----------------------------------------------
     * TODO: DB_create(4). Add >= 20 records (id, "name<i>", gpa) so the
     * array doubles at least twice (4 -> 8 -> 16 -> 32). After each add,
     * or every few adds, print DB_size and DB_capacity so the two
     * doublings are visible in the output.
     */
        int main(void) {
    DB *db = DB_create(4);
	for(int i =0; i<20; i++){
	char namebuf[20];
   	 sprintf(namebuf, "name%d", i);// fr fr i had no clue what sprintf is. ai cause i aint writin all that out.
	int add_result = DB_add(db, i, namebuf, 3.0 + i * 0.05);
printf("add %d result=%d size=%zu cap=%zu\n", i, add_result, DB_size(db), DB_capacity(db));
	printf("size=%zu cap=%zu\n", DB_size(db), DB_capacity(db));
}



	

    /* ---- 2. Find present + absent --------------------------------------
     * TODO: DB_find an id you added (print id/name/gpa from the returned
     * const Record *). DB_find an id you did NOT add (print "not found").
     * Note that you never write through the pointer -- it is const on
     * purpose; explain why in your README.
     */
const Record *foundit = DB_find(db,5);
	if(foundit == NULL){printf("not found\n");}
	if(foundit != NULL){ printf("id=%d name=%s gpa=%.2f\n",foundit->id,foundit->name,foundit->gpa);} 

const Record *couldntfind = DB_find(db,500);
        if(couldntfind == NULL){printf("not found\n");}
        if(couldntfind != NULL){ printf("id=%d name=%s gpa=%.2f\n",couldntfind->id,couldntfind->name,couldntfind->gpa);}


    /* ---- 3. Remove first, middle, last ---------------------------------
     * TODO: DB_remove the first id, DB_remove a middle id, DB_remove the
     * last id. After each removal call DB_print to show the DB. Removing
     * from the middle without leaving a hole is the interesting case --
     * your README states whether you shift the tail down or swap the
     * last element into the gap.
     */
DB_remove(db, 0);    /* first id */
DB_print(db);

DB_remove(db, 10);   /* a middle id */
DB_print(db);

DB_remove(db, 19);   /* last id */
DB_print(db);
    /* ---- 4. Duplicate add fails ----------------------------------------
     * TODO: DB_add an id that is still present. Check that the return
     * value is 0 and DB_size did not change.
     */
size_t sizecheck = DB_size(db);
        int check = DB_add(db,5,"Dupeeeeee",3.0);
        size_t temp = DB_size(db);
        if((temp == sizecheck) && (check == 0)){printf("all is good\n");}
        else{printf("dat shi sucks\n");}
    /* ---- 5. Save + destroy + create + load round trip ------------------
     * TODO:
     *   - DB_save(db, "records.txt")
     *   - DB_destroy(db); db = NULL;   // hygiene
     *   - db = DB_create(4)
     *   - DB_load(db, "records.txt")
     *   - DB_print(db) -- must match what you saved
     */
int save_result = DB_save(db, "records.txt");// AI generated
printf("save result=%d (expect 1)\n", save_result);

DB_destroy(db);
db = NULL;

db = DB_create(4);
int load_result = DB_load(db, "records.txt");
printf("load result=%d (expect 1)\n", load_result);

DB_print(db);
    /* ---- 6. Malformed file fails cleanly -------------------------------
     * TODO: DB_load(db, "bad_records.txt"). Check the return value is 0.
     * The DB must still be usable after this call (no crash, no leak).
     * Then DB_destroy the final DB so the whole program is
     * valgrind-clean.
     */
int bad_load_result = DB_load(db, "bad_records.txt");//AI generated
printf("load bad file result=%d (expect 0)\n", bad_load_result);
printf("db still usable, size=%zu\n", DB_size(db));

DB_destroy(db);
db = NULL;

return 0;

}

