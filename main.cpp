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

int main(void) {
    /* ---- 1. Create + grow ----------------------------------------------
     * TODO: DB_create(4). Add >= 20 records (id, "name<i>", gpa) so the
     * array doubles at least twice (4 -> 8 -> 16 -> 32). After each add,
     * or every few adds, print DB_size and DB_capacity so the two
     * doublings are visible in the output.
     */

    /* ---- 2. Find present + absent --------------------------------------
     * TODO: DB_find an id you added (print id/name/gpa from the returned
     * const Record *). DB_find an id you did NOT add (print "not found").
     * Note that you never write through the pointer -- it is const on
     * purpose; explain why in your README.
     */

    /* ---- 3. Remove first, middle, last ---------------------------------
     * TODO: DB_remove the first id, DB_remove a middle id, DB_remove the
     * last id. After each removal call DB_print to show the DB. Removing
     * from the middle without leaving a hole is the interesting case --
     * your README states whether you shift the tail down or swap the
     * last element into the gap.
     */

    /* ---- 4. Duplicate add fails ----------------------------------------
     * TODO: DB_add an id that is still present. Check that the return
     * value is 0 and DB_size did not change.
     */

    /* ---- 5. Save + destroy + create + load round trip ------------------
     * TODO:
     *   - DB_save(db, "records.txt")
     *   - DB_destroy(db); db = NULL;   // hygiene
     *   - db = DB_create(4)
     *   - DB_load(db, "records.txt")
     *   - DB_print(db) -- must match what you saved
     */

    /* ---- 6. Malformed file fails cleanly -------------------------------
     * TODO: DB_load(db, "bad_records.txt"). Check the return value is 0.
     * The DB must still be usable after this call (no crash, no leak).
     * Then DB_destroy the final DB so the whole program is
     * valgrind-clean.
     */

    printf("lab2 driver: TODO\n");
    return 0;
}
