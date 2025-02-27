// SPDX-License-Identifier: Apache-2.0
/*
Copyright (C) 2023 The Falco Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "actions.h"
#include "helpers.h"
#include "../app.h"

using namespace falco::app;
using namespace falco::app::actions;

falco::app::run_result falco::app::actions::print_ignored_events(const falco::app::state& s) {
	if(!s.options.print_ignored_events) {
		return run_result::ok();
	}

	std::cout << "Ignored syscall(s):" << std::endl;
	for(const auto& it : libsinsp::events::sc_set_to_event_names(falco::app::ignored_sc_set())) {
		std::cout << "- " << it.c_str() << std::endl;
	}
	std::cout << std::endl;

	return run_result::exit();
}
