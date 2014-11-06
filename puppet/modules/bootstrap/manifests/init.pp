# vagrant/puppet/modules/mysql/manifests/init.pp
class bootstrap {

  exec { 'setup-node':
    unless => 'which node',
    command => 'curl -sL https://deb.nodesource.com/setup | sudo bash -',
    path => ['/bin', '/usr/bin'],
    require => [Exec['apt-get update'], Package['curl']],
  }

  package { ['nodejs']:
    ensure => latest,
    require => Exec['setup-node'],
  }

  file { '/bootstrap':
    ensure => 'link',
    target => '/vagrant/bootstrap-3.3.0',
  }

  exec { 'install-less-global':
    unless => 'which lessc',
    command => 'npm install -g less',
    path => ['/bin', '/usr/bin'],
    require => Package['nodejs'],
  }

  exec { 'install-grunt-global':
    unless => 'which grunt',
    command => 'npm install -g grunt-cli',
    path => ['/bin', '/usr/bin'],
    require => Package['nodejs'],
  }
  
  exec { 'install-bootstrap-deps':
    creates => '/bootstrap/node_modules',
    command => 'npm install',
    cwd => '/bootstrap',
    path => ['/bin', '/usr/bin'],
    require => [Exec['install-grunt-global'],File['/bootstrap']],
  }
}
