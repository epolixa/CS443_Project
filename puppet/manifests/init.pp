exec { 'apt-get update':
  path => '/usr/bin',
}

package { 'emacs':
  ensure => present,
}

package { 'curl':
  ensure => present,
}

package { 'build-essential':
  ensure => present,
}

file { '/var/www/':
  ensure => 'directory',
}

include nginx, php, mysql, bootstrap
