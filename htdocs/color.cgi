#!/usr/bin/perl -Tw

use strict;
use warnings;
use CGI;

my($cgi) = new CGI;

print $cgi->header;
print "nihoa";

my($color) = "blue";
$color = $cgi->param('color') if defined $cgi->param('color');
print "color $color \n";

print $cgi->start_html(-title => uc($color),
                       -BGCOLOR => $color);
print $cgi->h1("This is $color");
print $cgi->end_html;
