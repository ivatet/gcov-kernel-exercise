/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */
#include <linux/module.h>
#include <linux/kernel.h>

static void gt_multiple_check(int i, int n)
{
	if (i % n == 0) {
		printk(KERN_INFO "Yay! The %d is a multiple of %d\n", i, n);
	}
}

static int __init gt_init(void)
{
	int i;

	printk(KERN_INFO "Hello world!\n");

	for (i = 1; i < 42; i++) {
		gt_multiple_check(i, 17);
		gt_multiple_check(i, 23);
	}

	return 0;
}

static void __exit gt_cleanup(void)
{
	printk(KERN_INFO "Goodbye world!\n");
}

module_init(gt_init);
module_exit(gt_cleanup);

MODULE_LICENSE("GPL");
