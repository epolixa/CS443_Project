# vagrant/puppet/modules/mysql/manifests/init.pp
class mysql {
  
  package { ['mysql-server']:
    ensure => present,
    require => Exec['apt-get update'],
  }

  service { 'mysql':
    ensure => running,
    require => Package['mysql-server'],
  }

  file { '/etc/mysql/my.cnf':
    source => 'puppet:///modules/mysql/my.cnf',
    require => Package['mysql-server'],
    notify => Service['mysql'],
  }

  exec { 'set-mysql-password':
    onlyif => 'sudo mysqladmin -uroot -proot status',
    command => "mysqladmin -uroot password testpassword1",
    path => ['/bin', '/usr/bin'],
    require => Service['mysql'],
  }
}
