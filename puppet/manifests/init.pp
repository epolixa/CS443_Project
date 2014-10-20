exec { 'apt-get update':
     path => '/usr/bin',
}

package { 'emacs':
	ensure => present,
}

file { '/var/www/':
     ensure => 'directory',
}
include nginx, php, mysql