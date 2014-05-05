
var mountFolder = function (connect, dir) {
  return connect.static(require('path').resolve(dir));
};

module.exports = function (grunt) {
	// Load
	grunt.loadNpmTasks('grunt-contrib-connect');
	grunt.loadNpmTasks('grunt-open');
	grunt.loadNpmTasks('grunt-contrib-clean');
	grunt.loadNpmTasks('grunt-contrib-watch');
	grunt.loadNpmTasks('grunt-shell');

	var jsCommand = 'em++',
		exeCommand = 'clang++';


	// Get files to compile
	var cppFiles = grunt.file.expand('src/**/*.cpp');
  	cppFiles = cppFiles.join(' ');

  	var args = [
  		'-O0',
  		'-Wno-c++11-extensions'
  	];

  	var outfileJS = '-o app/js/build/panther-0.0.0.js',
  		outfileEXE = '-o panther-0.0.0.out';
  	args = args.join(' ');

	// Init
	grunt.initConfig({
		connect : {
			options : {
				port : 9000,
				hostname : 'localhost',
				keepalive : false
			},
			game : {
				options : {
					middleware : function(connect){
						return [
							mountFolder(connect, './app')
						];
					}
				}
			}
		},
		open : {
			server : {
				path : 'http://localhost:<%= connect.options.port %>'
			}
		},
		clean : {
			server : 'temp',
			js : 'app/js/build/**/*'
		},
		watch : {
			livereload : {
				options : {
					livereload : true
				},
				files : [
					'./app/**/*.js'
				]
			}
		},
		shell : {
			compileJS : {
				command : jsCommand+' '+cppFiles+' '+args+' '+outfileJS 
			},
			compileEXE : {
				command : exeCommand+' '+cppFiles+' '+args+' -std=c++11 -stdlib=libc++  -I /usr/lib/c++/v1/ -L /usr/lib/c++/v1/ '+outfileEXE
			}
		}
	});

	// Register tasks
	grunt.registerTask('server', [
		'clean:server',
		'connect:game',
		'open:server',
		'watch:livereload'
	]);

	grunt.registerTask('build', [
		'clean:js',
		'shell:compileJS',
	]);
}